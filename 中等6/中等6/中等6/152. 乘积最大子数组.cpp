#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
/*
	152. 乘积最大子数组
    动态规划
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < len; i++) {
            maxF[i] = max(maxF[i-1] * nums[i], max(minF[i-1]*nums[i], nums[i]));
            minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};