#include<iostream>
#include<vector>
using namespace std;
/*
	162. 寻找峰值
        要求使用时间复杂度O(logn)
        二分法（考虑到nums[-1] = nums[n] = 负无穷）
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};