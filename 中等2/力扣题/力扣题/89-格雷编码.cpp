#include<iostream>
#include<vector>
using namespace std;
/*
	���ױ��룺
		�ҹ��ɣ����
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		while (n--) {
			for (int i = ans.size() - 1; i >= 0; --i) {
				//�����һλ��ʼ�ƶ�
				ans[i] <<= 1;
				//Ȼ������ƺ�����ּ�1����ans��
				ans.push_back(ans[i] + 1);
			}
		}
		return ans;
	}
};