#include<iostream>
#include<vector>
using namespace std;
/*
	207. 课程表
    使用拓扑排序
*/
class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    //深度优先遍历该门课
    void dfs(int u) {
        visited[u] = 1;     //更新状态
        for (int v : edges[u]) {        //遍历选修第u门课之后，可以修哪些课
            if (visited[v] == 0) {  //如果第v门课没修，进行进行深度遍历
                dfs(v);
                if (!valid) {       //如果出现了环，就退出
                    return;
                }
            }
            else if (visited[v] == 1) { //表示第v门课也在搜索中，就会出现环，退出
                valid = false;
                return ;
            }
        }
        visited[u] = 2;     //表示搜索结束，并且没有出现环
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //确定容器大小
        edges.resize(numCourses);
        visited.resize(numCourses);
        //初始化edges，选了该课可以修哪些课
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        //遍历numCouses门课，加上valid是为了判断中途有没有环，有环的话直接退出
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {     //没有遍历过，才可以进行深度优先遍历
                dfs(i);
            }
        }
        return valid;
    }
};