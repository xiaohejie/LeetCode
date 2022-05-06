#include<iostream>
#include<vector>
using namespace std;
/*
	乘积小于K的子数组：
		使用滑动窗口（双指针）：
		（1）让左右指针一开始都直指向0
		（2）{
				乘积和从第0个数开始相乘；
				如果（left <= right && 乘积和>=k）{
					成绩和去掉左指针（prod /= nums[left]）;
					left++;
				}
				计算结果需要更新；（right - left + 1：
										这里的意思是，如果i连乘到j还是小于k的话，说明里面的每个数都小于k）
		}
		（3）返回结果
*/
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int len = nums.size();
		int ans = 0;
		int left = 0, right = 0;
		int prod = 1;
		for (right = 0; right < len; right++) {
			prod *= nums[right];
			while (left <= right && prod >= k) {
				prod /= nums[left];
				left = left + 1;
			}
			//这里的意思是，如果i连乘到j还是小于k的话，说明里面的每个数都小于k
			ans += (right - left + 1);
		}
		return ans;
	}
};