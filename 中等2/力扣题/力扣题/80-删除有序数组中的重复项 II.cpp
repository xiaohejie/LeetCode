#include<iostream>
#include<vector>
using namespace std;
/*
	ɾ�������е��ظ���II��
		
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2) {
			//�������С�ڵ���2����ֱ���˳�
			return len;
		}
		int p = 2;	//�ӵڶ���λ�ÿ�ʼ�Ƚ�
		for (int i = 2; i < len; i++) {
			//��ǰһ����ǰһ�����бȽ�
			if (nums[i] == nums[p-2]) {
			}
			else {
				nums[p] = nums[i];
				p++;
			}
		}
		return p;
	}
};

/*
	          p
	1 1 2 2 3 3 
	          i
*/	