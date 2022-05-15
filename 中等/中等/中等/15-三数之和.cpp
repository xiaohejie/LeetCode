#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	三数之和：
		
*/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			//定义第一个数
			if (i > 0 && nums[i] == nums[i-1]) {
				continue;
			}
			int z = nums.size() - 1;
			for (int j = i + 1; j < nums.size(); j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}
				while (z > j && nums[i] + nums[j] + nums[z] > 0) {
					z--;
				}
				if (j == z) {
					break;
				}
				if (nums[i] + nums[j] + nums[z] == 0) {
					res.push_back({ nums[i], nums[j], nums[z] });
				}
			}
		}
		return res;
	}
};