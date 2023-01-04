#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	189. 轮转数组
        对数组进行翻转
*/
class Solution {
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        //对数组进行翻转
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k , nums.size() - 1);
    }
};
