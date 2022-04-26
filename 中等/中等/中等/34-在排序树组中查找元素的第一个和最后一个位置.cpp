#include<iostream>
#include<vector>
using namespace std;
/*
	在排序数组中查找元素的第一个和最后一个位置：
		使用二分查找：
			分别写两个函数来确定左边界和有边界
*/
class Solution {
public:
	//找出最左边的target
	int findLeftTarget(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				//leftTarget就在[mid+1, right]之间
				left = mid + 1;
			}
			else if (nums[mid] == target) {
				//leftTarget就在[left, mid]之间
				right = mid;
			}
			else {//nums[mid] > target
				//leftTarget就在[left, mid-1]之间
				right = mid - 1;
			}
		}
		//如果最后得出来的Target != num[left]
		if (target != nums[left]) {
			return -1;
		}
		else {
			return left;
		}
	}
	//找出最右边的target
	int findRightTarget(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right +1 ) / 2;			//注意这里要加一（**********************）
			if (nums[mid] < target) {
				//rightTarget就在[mid+1, right]之间
				left = mid + 1;
			}
			else if (nums[mid] == target) {
				//rightTarget就在[mid, right]之间
				left = mid;
			}
			else {//nums[mid] > target
				//rightTarget就在[left, mid-1]之间
				right = mid - 1;
			}
		}
		//如果最后得出来的Target != num[left]
		if (target != nums[left]) {
			return -1;
		}
		else {
			return right;
		}
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) {
			//数组长度为0
			return { 0,0 };
		}
		//找出最左边的target
		int leftPos = findLeftTarget(nums, target);
		if (leftPos == -1) {
			return { -1, -1 };
		}
		//找出最右边的target
		int rightPos = findRightTarget(nums, target);

		return { leftPos, rightPos };
	}
};