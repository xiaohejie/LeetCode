#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
/*
	128. 最长连续序列	
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        //先进行排序
        sort(nums.begin(), nums.end());
        vector<int> vec;        //用来存储前后值的差
        vec.push_back(0);
        //遍历数组，记录前后两个数字的差
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
            vec.push_back(nums[i] - nums[i - 1]);
        }
        int maxLength = 0;
        int len = 0;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == 1) {
                len++;
                maxLength = max(maxLength, len);
            }
            else {
                //不连续了，先进行比较，然后在置零
                maxLength = max(maxLength, len);
                len = 0;
            }
        }
        return maxLength + 1;
    }
};