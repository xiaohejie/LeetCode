#include<iostream>
#include<vector>
using namespace std;
/*
	��Ծ��Ϸ��
		����һ���Ǹ��������� nums �������λ������� ��һ���±� ��
		�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶�
		�ж����Ƿ��ܹ��������һ���±ꡣ

	˼·��
	�ҵ�ÿ��������Ե������Զλ�ã������ǰn-1���㻹�ǵ����˵Ļ��ͷ���false
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxRoute = 0;
		for (int i = 0; i < n; i++) {
			if (i <= maxRoute) {		//i�ķ�ΧҪ��maxRoute���Ե���ĵ㣨Ҫ�ڵ����˵�ǰ���£�
				maxRoute = max(maxRoute, i + nums[i]);		//���¿��Ե������Զ�ĵ�
				if (maxRoute >= n - 1) {	//ӦΪ��0�����Ѿ��߹�
					return true;
				}
			}
		}
		return false;
	}
};