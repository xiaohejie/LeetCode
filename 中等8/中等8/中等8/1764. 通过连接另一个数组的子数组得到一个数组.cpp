#include<iostream>
#include<vector>
using namespace std;
/*
	1764. 通过连接另一个数组的子数组得到一个数组
*/
class Solution {
    bool check(vector<int>& group, vector<int>& nums, int k) {
        if (k + group.size() > nums.size()) {
            return false;       //长度不够，直接返回false
        }
        for (int j = 0; j < group.size(); j++) {
            if (group[j] != nums[k + j]) {
                return false;
            }
        }
        return true;
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0;
        for (int k = 0; k < nums.size() && i < groups.size();) {
            //如果从k开始，nums数组中有子数组为groups[i]
            if (check(groups[i], nums, k)) {
                k += groups[i].size();      //则下一次遍历的开头
                i++;            //下一次遍历的groups中的成员
            }
            else {
                k++;    //没有的话，遍历nums中的下一个元素
            }
        }
        return i == groups.size();  //最后判断有没有遍历结束
    }
};