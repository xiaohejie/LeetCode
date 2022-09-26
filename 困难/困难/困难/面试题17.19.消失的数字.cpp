#include<iostream>
#include<vector>
using namespace std;
/*
	面试题 17.19. 消失的两个数字
        使用位运算
        注解里面有专治消失的树的三种解法
*/
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int len = nums.size();
        int N = len + 2;
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum ^= nums[i];
        }
        for (int i = 1; i <= N; i++) {
            sum ^= i;
        }
        //得到两个数的异或和sum
        //使用x&-x算出x的二进制表示中最低位的1，算lsb很重要
        int lsb = (sum == INT_MIN ? sum : sum & (-sum));
        int num1 = 0, num2 = 0;
        for (auto& num : nums) {
            if (num & lsb) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (i & lsb) {
                num1 ^= i;
            }
            else {
                num2 ^= i;
            }
        }
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};