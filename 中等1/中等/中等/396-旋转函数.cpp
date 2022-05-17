#include<iostream>
#include<vector>
using namespace std;
/*
	旋转函数：
		F(0) = 0*arr[0] + 1*arr[1] + .... + (n-1)arr[n-1];
		F(1) = 1*arr[0] + 2*arr[1] + .... + (n-1)arr[n-2] + 0arr[n-1] = sumArr + F(0) - narr[n-1];
		F(2) = 2*arr[0] + 3*arr[1] + .... + (n-1)arr[n-3] + 0*arr[n-2] + 1*arr[n-1] = sumArr + F(1) - narr[n-2]
	所以：
		F(k) = F(k - 1) +sumArr - n* arr[n - k];		
*/
class Solution {
public:
	int maxRotateFunction(vector<int>& nums) {
		int sumArr = 0;
		int f = 0;
		int maxS = 0;
		//求sum
		for (auto& num : nums) {
			sumArr += num;
		}
		//求F(0)
		for (int i = 0; i < nums.size(); i++) {
			f += i * nums[i];
		}
		maxS = f;
		for (int i = nums.size() - 1; i > 0; i--) {
			f += sumArr - nums.size() * nums[i];
			maxS = max(maxS, f);
		}
		return maxS;
	}
};