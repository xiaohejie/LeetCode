#include<iostream>
#include<vector>
using namespace std;
/*
	�Ӽ���
		
*/
class Solution {
public:
	vector<vector<int>> ans;
	void dfs(vector<int>& nums, vector<int>& res, int start) {
		//������ֹ����
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
		ans.push_back(res);		//���ռ��Ž�ȥ
		dfs(nums, res, 0);
		return ans;
	}
	//vector<vector<int>> ans;
	//void dfs(vector<int>& nums, vector<int>& res, int start) {
	//	//������ֹ����
	//	if (start == nums.size()) {
	//		ans.push_back(res);
	//		return;
	//	}
	//	//����ǰ������res��
	//	res.push_back(nums[start]);
	//	//������һ����
	//	dfs(nums, res, start + 1);
	//	//����
	//	res.pop_back();
	//	dfs(nums, res, start + 1);
	//}
	//vector<vector<int>> subsets(vector<int>& nums) {
	//	vector<int> res;
	//	ans.push_back(res);		//���ռ��Ž�ȥ
	//	dfs(nums, res, 0);
	//	return ans;
	//}
};