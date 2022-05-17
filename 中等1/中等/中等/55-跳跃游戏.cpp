#include<iostream>
#include<vector>
using namespace std;
/*
	跳跃游戏：
		给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
		数组中的每个元素代表你在该位置可以跳跃的最大长度
		判断你是否能够到达最后一个下标。

	思路：
	找到每个数组可以到达的最远位置，如果到前n-1个点还是到不了的话就返回false
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxRoute = 0;
		for (int i = 0; i < n; i++) {
			if (i <= maxRoute) {		//i的范围要是maxRoute可以到达的点（要在到的了的前提下）
				maxRoute = max(maxRoute, i + nums[i]);		//更新可以到达的最远的点
				if (maxRoute >= n - 1) {	//应为第0个点已经走过
					return true;
				}
			}
		}
		return false;
	}
};