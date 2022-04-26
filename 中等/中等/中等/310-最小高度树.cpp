#include<iostream>
#include<vector>
#include <queue>
using namespace std;
/*
	��С�߶�����
		�ҳ�������������ڵ㣬�ҵ����ǵ��е�
*/
class Solution {
private:
    int degree[20001] = { 0 };      //ÿ���ڵ���ھ�����
    vector<int> map[20001];           //ÿ���ڵ���ھ���
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        for (auto edge : edges) {       //ÿ�����������ڵ�
            degree[edge[0]]++;
            degree[edge[1]]++;

            g[edge[0]].push_back(edge[1]);      //��edge[0]���ھӼӽ�ȥ        key�����      value���ھ���
            g[edge[1]].push_back(edge[0]);      //��edge[1]���ھӼӽ�ȥ
        }

        queue<int> q;                       //��ʱ�˿̵�Ҷ�ӽ����
        queue<int> tmp;
        int visited = 0;                    //��¼�ڵ�ĸ���
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                visited++;
            }
        }
        while (visited < n) {               //��visitС�ڽڵ�����
            while (!q.empty()) {
                int e = q.front(); q.pop();     //����ȡ��Ҷ�ӽ��
                for (auto v : g[e]) {
                    degree[v]--;
                    if (degree[v] == 1) {
                        tmp.push(v);
                        visited++;
                    }
                }
            }
            q.swap(tmp);
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        int* degree = new int[n];       //ÿ���ڵ���ھ�����
        //unordered_map<int, vector<int>> map;    //ÿ���ڵ���ھ���
        vector<vector<int>> map(n);

        //��ʼ���ھ��������ھӵ�����
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            //������һ���ھ��ǶԷ�
            degree[a]++;
            degree[b]++;

            //key���ڵ�   value���ھ���
            map[a].emplace_back(b);
            map[b].emplace_back(a);
        }
       /* for (auto num : map) {
            for (auto n : num) {
                cout << n << " ";
            }
            cout << endl;
        }*/

        //��ʱ�˿�Ҷ�ӽڵ���
        queue<int> leafNodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leafNodes.push(i);      //��Ҷ�ӽ�����leafNodes��
            }
        }
        //����ѭ��(��)
        while (leafNodes.size() > 0) {
            res.clear();

            int size = leafNodes.size();
            for (int i = 0; i < size; i++) {
                int leaf = leafNodes.front();
                leafNodes.pop();
                res.push_back(leaf);

                vector<int> neighbors = map[leaf];      //ĳ��Ҷ�ӽڵ���ھ���
                for (auto& neighbour : neighbors) {
                    degree[neighbour]--;        //�ھӵ��ھ�������1

                    if (degree[neighbour] == 1) {
                        //��һ�ֵ�Ҷ�ӽ��
                        leafNodes.push(neighbour);
                    }
                }
            }
        }
        return res;
    }
};