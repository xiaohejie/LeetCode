#include<iostream>
#include<vector>
using namespace std;
/*
	81-������ת�������飺
		���ҵ��������������ת
*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int index = 0;
		//�ҳ���תλ��
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i - 1]) {
				//��¼��תλ�� 
				index = i;
				break;
			}
		}
		//�������������index==0
		if (index == 0) {
			index = nums.size();
		}
		//cout << index << endl;
		//��target���±�
		if (target >= nums[0]) {
			cout << "����" << endl;
			for (int i = 0; i < index; i++) {
				if (target == nums[i]) {
					return true;
				}
			}
		}
		else {
			cout << "����" << endl;
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