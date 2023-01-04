#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	1971. Ѱ��ͼ���Ƿ����·��
        ��������������������������
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> vec(n);
        //��¼˫���
        for (auto& edge : edges) {
            vec[edge[0]].push_back(edge[1]);
            vec[edge[1]].push_back(edge[0]);
        }
        //ʹ�ö���
        vector<bool>judge(n, false);
        queue<int> q;
        q.push(source);
        judge[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == destination) { //����Ŀ��ֵ��ֱ���˳�
                break;
            }
            for (int next : vec[x]) {
                if (!judge[next]) {     //���û�б�����nextֵ
                    q.push(next);
                    judge[next] = true;
                }
            }
        }
        return judge[destination];
    }
};

//ʹ�������������
class Solution {
    bool dfs(int source, int destination, vector<vector<int>> vec, vector<bool> judge) {
        if (source == destination) {
            return true;
        }
        judge[source] = true;
        for (int next : vec[source]) {
            if (!judge[next] && dfs(next, destination, vec, judge)) {
                return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> vec(n);
        for (auto& edge : edges) {
            vec[edge[0]].push_back(edge[1]);
            vec[edge[1]].push_back(edge[0]);
        }
        vector<bool> judge(n, false);
        return dfs(source, destination, vec, judge);
    }
};