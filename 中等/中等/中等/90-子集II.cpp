#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	×Ó¼¯II£º
		
*/
class Solution {
public:
	vector<int> ans;
	vector<vector<int>> res;
	void dfs(vector<int>& nums, int start) {
		if (start >= nums.size()) {
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			if (i > start && nums[i] == nums[i-1]) {
				continue;
			}
			ans.push_back(nums[i]);
			res.push_back(ans);
			dfs(nums, i+1);
			ans.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		res.push_back(ans);
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return res;
	}
};