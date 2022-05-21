#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	462. 最少移动次数使数组元素相等 II:
		找他们的中位数
*/
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int count = 0;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int midNum = nums[len / 2];
		for (int i = 0; i < nums.size(); i++) {
			count += abs(nums[i] - midNum);
		}	
		return count;
	}
};