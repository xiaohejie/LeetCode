#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	565. 数组嵌套
        如果不进行初始化，会有超时
*/
class Solution {
public:
    int help(vector<int>& nums, int i, vector<int>& set) {
        //进行初始化
        int count = 0;
        int index = i;
        while (set[index]==0) {
            //表明该下标没有被遍历过
            count++;
            set[index] = true;
            //更新
            index = nums[index];
        }
        return count;
    }
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<int> set(nums.size());       //用来记录已经遍历过下标
        for (int i = 0; i < nums.size(); i++) {
            int count = help(nums, i, set);
            ans = max(ans, count);
        }
        return ans;
    }
};