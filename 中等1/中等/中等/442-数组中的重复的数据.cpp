#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	数组中的重复数据：
		不可以使用额外空间的话：
			可以先进行排序，然后再一一对应
*/
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		unordered_map<int, int>map;		//用来存数字和出现的次数
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]]++;
			if (map[nums[i]] == 2) {
				res.push_back(nums[i]);
			}
		}
		return res;
	}
};