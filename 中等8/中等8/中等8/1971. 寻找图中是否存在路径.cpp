#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	1971. 寻找图中是否存在路径
        广度优先搜索或者深度优先搜索
*/
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> vec(n);
        //记录双向边
        for (auto& edge : edges) {
            vec[edge[0]].push_back(edge[1]);
            vec[edge[1]].push_back(edge[0]);
        }
        //使用队列
        vector<bool>judge(n, false);
        queue<int> q;
        q.push(source);
        judge[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == destination) { //等于目标值，直接退出
                break;
            }
            for (int next : vec[x]) {
                if (!judge[next]) {     //如果没有遍历过next值
                    q.push(next);
                    judge[next] = true;
                }
            }
        }
        return judge[destination];
    }
};

//使用深度优先搜索
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