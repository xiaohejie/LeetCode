#include<iostream>
#include<vector>
using namespace std;
/*
	下一个排列：
		思路：
			从最后一个字符开始像前找，直到找到当前字符小于后一个字符，标记为i
			在从最后一个字符向前找，直到nums[i]大于nums[j]，调用swap反转、
			最后将i后面的字符全部翻转
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {

	}
};