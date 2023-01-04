#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*
	1760. 袋子里最少数目的球
    使用二分查找法
*/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i, m, l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) / 2;      //找到中间值，判断需要多少次
            for (i = m = 0; i < nums.size(); i++) {
                m += (nums[i] - 1) / mid;       //计算需要多少次
            }
            //使用二分法  
            if (m <= maxOperations) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};