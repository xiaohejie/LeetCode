#include<iostream>
#include<vector>
#include <queue>
using namespace std;
/*
	最小高度树：
		找出距离最长的两个节点，找到它们的中点
*/
class Solution {
private:
    int degree[20001] = { 0 };      //每个节点的邻居数量
    vector<int> map[20001];           //每个节点的邻居们
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        for (auto edge : edges) {       //每条边有两个节点
            degree[edge[0]]++;
            degree[edge[1]]++;

            g[edge[0]].push_back(edge[1]);      //把edge[0]的邻居加进去        key：结点      value：邻居们
            g[edge[1]].push_back(edge[0]);      //把edge[1]的邻居加进去
        }

        queue<int> q;                       //此时此刻的叶子结点们
        queue<int> tmp;
        int visited = 0;                    //记录节点的个数
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                visited++;
            }
        }
        while (visited < n) {               //当visit小于节点数量
            while (!q.empty()) {
                int e = q.front(); q.pop();     //挨个取出叶子结点
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
        int* degree = new int[n];       //每个节点的邻居数量
        //unordered_map<int, vector<int>> map;    //每个节点的邻居们
        vector<vector<int>> map(n);

        //初始化邻居数量和邻居的名字
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            //至少有一个邻居是对方
            degree[a]++;
            degree[b]++;

            //key：节点   value：邻居们
            map[a].emplace_back(b);
            map[b].emplace_back(a);
        }
       /* for (auto num : map) {
            for (auto n : num) {
                cout << n << " ";
            }
            cout << endl;
        }*/

        //此时此刻叶子节点们
        queue<int> leafNodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leafNodes.push(i);      //将叶子结点放入leafNodes中
            }
        }
        //遍历循环(减)
        while (leafNodes.size() > 0) {
            res.clear();

            int size = leafNodes.size();
            for (int i = 0; i < size; i++) {
                int leaf = leafNodes.front();
                leafNodes.pop();
                res.push_back(leaf);

                vector<int> neighbors = map[leaf];      //某个叶子节点的邻居们
                for (auto& neighbour : neighbors) {
                    degree[neighbour]--;        //邻居的邻居数量减1

                    if (degree[neighbour] == 1) {
                        //新一轮的叶子结点
                        leafNodes.push(neighbour);
                    }
                }
            }
        }
        return res;
    }
};