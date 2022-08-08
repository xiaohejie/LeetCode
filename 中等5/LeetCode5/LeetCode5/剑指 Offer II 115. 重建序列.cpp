#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
/*
	剑指 Offer II 115. 重建序列
         拓扑排序
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        //找出sequences所有的最短超序列，唯一再与nums进行比较，不唯一直接false；
        int n = nums.size();
        vector<int> indegresses(n+1);       //用来存储结点的入度，使用n+1是因为从i-n，不包含0，但也要放进去
        vector<unordered_set<int>> graph(n + 1);  //用来存储sequences组成的有向图

        for (auto& sequence : sequences) {
            for (int i = 1; i < sequence.size(); i++) {
                //将sequence中的字符先后顺序入图，next对应的入度加1
                int prev = sequence[i - 1], next = sequence[i];
                if (!graph[prev].count(next)) {
                    //if是防止sequence中有重复
                    graph[prev].emplace(next);      //记录该字符后面的字符
                    indegresses[next]++;            //记录字符的位置
                }
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegresses[i] == 0) {
                //选择入度为0的入队
                q.push(i);
            }
        }
        while (!q.empty()) {
            if (q.size() > 1) {
                //存在两个即以上的入度为0说明不唯一
                return false;
            }
            int num = q.front();
            q.pop();
            for (int next : graph[num]) {
                indegresses[next]--;
                //之前的结点出对了，所以它所指向的数入度减1
                if (indegresses[next] == 0) {
                    q.push(next);
                }
            }
        }
        return true;
    }
};

