#include<iostream>
#include<vector>
using namespace std;
/*
	��һ�����У�
		˼·��
			�����һ���ַ���ʼ��ǰ�ң�ֱ���ҵ���ǰ�ַ�С�ں�һ���ַ������Ϊi
			�ڴ����һ���ַ���ǰ�ң�ֱ��nums[i]����nums[j]������swap��ת��
			���i������ַ�ȫ����ת
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 2;
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}
		if (i >= 0) {
			int j = nums.size() - 1;
			while (j >= 0 && nums[i] >= nums[j]) {
				j--;
			}
			swap(nums[i], nums[j]);
		}
		reverse(nums.begin() + i + 1, nums.end());
	}
};