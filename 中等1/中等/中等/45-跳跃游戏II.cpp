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
			这里要注意一个细节，就是 for 循环中，i < nums.length - 1，少了末尾。
			因为开始的时候边界是第 00 个位置，steps 已经加 11 了。
			如下图，如果最后一步刚好跳到了末尾，此时 steps 其实不用加 11 了。
			如果是 i < nums.length，i 遍历到最后的时候，会进入 if 语句中，steps 会多加 11。
		*/
		for (int i = 0; i < n - 1; i++) {		//这里为什么是n-1不太懂（看LeetCode题解	第三个）
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