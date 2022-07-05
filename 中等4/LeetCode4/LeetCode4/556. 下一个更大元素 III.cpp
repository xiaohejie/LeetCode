#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	556. 下一个更大元素 III（与下一个排列类似）
    {
        从后向前遍历n，直到找到前一个数小于下一个数的下标
        如果遍历结束，还没有的话，就直接返回-1
        否则的话{
            再次进行遍历，直到找到nums[j] < nums[i]的下标
        }
        交换i和j位置
        然后将其中的数组进行置换
    }
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int i = nums.length() - 2;
        while (i >= 0 && nums[i] > nums[i+1]) {
            i--;
        }
        if (i < 0) {
            return -1;
        }
        int j = nums.length() - 1;
        while (j >= 0 && nums[i] > nums[j]) {
            j--;
        }

        //交换i和j的位置
        swap(nums[i], nums[j]);
        //再进行倒置
        reverse(nums.begin() + i + 1, nums.end());
        int ans = stoi(nums);
        return ans;
    }
};