#include<iostream>
#include<vector>
using namespace std;
/*
	81-搜索旋转排序数组：
		先找到在哪里进行了旋转
*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int index = 0;
		//找出旋转位置
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				//记录旋转位置 
				index = i;
				break;
			}
		}
		//如果遍历结束，index==0
		if (index == 0) {
			index = nums.size();
		}
		//cout << index << endl;
		//找target的下标
		if (target >= nums[0]) {
			cout << "哪里" << endl;
			for (int i = 0; i < index; i++) {
				if (target == nums[i]) {
					return true;
				}
			}
		}
		else {
			cout << "这里" << endl;
			for (int i = index; i < nums.size(); i++) {
				cout << i << endl;
				if (nums[i] == target) {
					return true;
				}
			}
		}
		return false;
	}
};