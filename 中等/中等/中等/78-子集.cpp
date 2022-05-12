#include<iostream>
#include<vector>
using namespace std;
/*
	子集：
		
*/
class Solution {
public:
	vector<vector<int>> ans;
	void dfs(vector<int>& nums, vector<int>& res, int start) {
		//回溯中止条件
		if (start == nums.size()) {
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			res.push_back(nums[i]);
			ans.push_back(res);
			dfs(nums, res, i+1);
			res.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> res;
		ans.push_back(res);		//将空集放进去
		dfs(nums, res, 0);
		return ans;
	}
	//vector<vector<int>> ans;
	//void dfs(vector<int>& nums, vector<int>& res, int start) {
	//	//回溯中止条件
	//	if (start == nums.size()) {
	//		ans.push_back(res);
	//		return;
	//	}
	//	//将当前点塞入res中
	//	res.push_back(nums[start]);
	//	//进入下一个点
	//	dfs(nums, res, start + 1);
	//	//回溯
	//	res.pop_back();
	//	dfs(nums, res, start + 1);
	//}
	//vector<vector<int>> subsets(vector<int>& nums) {
	//	vector<int> res;
	//	ans.push_back(res);		//将空集放进去
	//	dfs(nums, res, 0);
	//	return ans;
	//}
};