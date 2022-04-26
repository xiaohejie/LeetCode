#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	组合总和2：
		给定一个候选人编号的集合 candidates 和一个目标数 target ，
		找出 candidates 中所有可以使数字和为 target 的组合。
		candidates 中的每个数字在每个组合中只能使用 一次 。
		注意：解集不能包含重复的组合。 
*/
class Solution {
public:
	void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> res, int index) {
		if (index >= candidates.size() || target < candidates[index]) {
			return;
		}
		if (target == 0) {
			ans.push_back(res);
			return;
		}
		//选择直接跳过当前数
		int i = index;
		while (i < candidates.size() && candidates[i] == candidates[index]) {
			i++;
		}
		if (i < candidates.size()) {
			dfs(candidates, target, ans, res, i);
		}

		//选择当前数，选完之后就不可以再选
		if (target - candidates[index] >= 0) {
			res.push_back(candidates[index]);
			dfs(candidates, target - candidates[index], ans, res, index + 1);

			res.pop_back();	
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> res;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, ans, res, 0);
		return ans;
	}
};
