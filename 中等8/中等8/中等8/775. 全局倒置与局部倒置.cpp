#include<iostream>
#include<vector>
using namespace std;
/*
	775. 全局倒置与局部倒置
*/
class Solution {
public:
    //超时
    /*bool isIdealPermutation(vector<int>& nums) {
        int countA = 0, countB = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] > nums[j]){
                    countA++;
                }
            }
        }
        for (int i = 0; i < len-1; i++) {
            if (nums[i] > nums[i+1]) {
                countB++;
            }
        }
        return countA == countB;
    }*/

    //一个局部倒置一定是一个全局倒置，因此只要判断数组中局部倒置的数量是否与全局倒置的数量相等，只需要检查有没有非局部倒置就可以了
    //这里的非局部倒置指的是nums[i] > nums[j]，其中i < j-1（不是相邻点，依然存在nums[i] > nums[j]）
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minStuff = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            //判断有没有全局倒置，但不是局部倒置
            if (nums[i] > minStuff) {
                return false;
            }
            //若没有全局倒置，则继续向前进行判断
            minStuff = min(minStuff, nums[i + 1]);
        }
        return true;
    }
};