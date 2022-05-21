#include<iostream>
#include<vector>
using namespace std;
/*
	跳跃游戏II：
		使用两步贪心（挺难理解）：既要考虑当前最优，也要考虑下一步最优
*/
class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int curMax = 0, nextMax = 0;//curMax：指当前能够跳的最远距离，nextMax：指当前加上下一步能够跳的最远距离
		int step = 0;		//多少步
		/*
		* （看LeetCode题解）
			在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，
			我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。
			如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，
			因此我们不必访问最后一个元素。
		*/
		for (int i = 0; i < n - 1; i++) {		//这里为什么是n-1不太懂（因为题目中假设总是可以到达最后一个位置）
			if (i + nums[i] > nextMax) {
				//更新nextMax
				nextMax = i + nums[i];
			}
			if (i == curMax) {
				//当i走到curMax时，就必须得跳
				step++;
				curMax = nextMax;	
			}
		}
		return step;
	}
};