#include<iostream>
#include<vector>
using namespace std;
/*
	所有可能的路径：
		使用回溯法
*/
class Solution {
public:
	vector<int> ans;
	vector<vector<int>> res;
	void backtrack(vector<vector<int>>& graph, int start) {
		ans.push_back(start);
		if (start == graph.size() - 1) {
			//如果到达最后的一个点，就可以放进res
			res.push_back(ans);
		}
		for (auto g : graph[start]) {
			//对第i个点可以到达的其他点进行回溯
			backtrack(graph, g);
		}
		ans.pop_back();		//回溯，去掉最后一个元素
		return;
	}
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int len = graph.size();
		backtrack(graph, 0);
		return res;
	}
};