#include<iostream>
#include<vector>
using namespace std;
/*
	�����������в���Ԫ�صĵ�һ�������һ��λ�ã�
		ʹ�ö��ֲ��ң�
			�ֱ�д����������ȷ����߽���б߽�
*/
class Solution {
public:
	//�ҳ�����ߵ�target
	int findLeftTarget(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				//leftTarget����[mid+1, right]֮��
				left = mid + 1;
			}
			else if (nums[mid] == target) {
				//leftTarget����[left, mid]֮��
				right = mid;
			}
			else {//nums[mid] > target
				//leftTarget����[left, mid-1]֮��
				right = mid - 1;
			}
		}
		//������ó�����Target != num[left]
		if (target != nums[left]) {
			return -1;
		}
		else {
			return left;
		}
	}
	//�ҳ����ұߵ�target
	int findRightTarget(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right +1 ) / 2;			//ע������Ҫ��һ��**********************��
			if (nums[mid] < target) {
				//rightTarget����[mid+1, right]֮��
				left = mid + 1;
			}
			else if (nums[mid] == target) {
				//rightTarget����[mid, right]֮��
				left = mid;
			}
			else {//nums[mid] > target
				//rightTarget����[left, mid-1]֮��
				right = mid - 1;
			}
		}
		//������ó�����Target != num[left]
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
			//���鳤��Ϊ0
			return { 0,0 };
		}
		//�ҳ�����ߵ�target
		int leftPos = findLeftTarget(nums, target);
		if (leftPos == -1) {
			return { -1, -1 };
		}
		//�ҳ����ұߵ�target
		int rightPos = findRightTarget(nums, target);

		return { leftPos, rightPos };
	}
};