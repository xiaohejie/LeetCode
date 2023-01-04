#include<iostream>
#include<vector>
using namespace std;
/*
	213. 打家劫舍 II
        使用动态规划：
            如果从第一件房子开始，就不能遍历最后一间
            如果要遍历最后一间，就需要从第二间开始
*/
class Solution {
    int help(vector<int>& nums, int start, int end) {
        //创建动态容器
        vector<int> vec(end - start + 1);
        //初始化动态容器
        vec[0] = nums[start];
        vec[1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            vec[i - start] = max(vec[i - start - 2] + nums[i], vec[i- start - 1]);
        }
        return vec[end - start];
    }
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return  nums[0];
        }
        else if (len == 2) {
            return max(nums[1], nums[1]);
        }
        else {
            return max(help(nums, 0, len - 2), help(nums, 1, len - 1));
        }
    }
};