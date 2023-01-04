#include<iostream>
#include<vector>
using namespace std;
/*
	198. 打家劫舍
        使用动态规划
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 0) {
            return 0;
        }
        //创建动态容器
        vector<int> vec(n);
        //初始化动态容器
        vec[0] = nums[0];
        vec[1] = max(nums[0], nums[1]);
        //状态转换方程
        int num1 = 0, num2 = 0;
        for (int i = 2; i < n; i++) {
            num1 = vec[i - 1];
            num2 = vec[i - 2] + nums[i];
            vec[i] = max(num1, num2);
        }
        return vec[n - 1];
    }
};