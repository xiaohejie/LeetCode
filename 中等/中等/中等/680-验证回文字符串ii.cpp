#include<iostream>
using namespace std;
/*
	��֤�����ַ�����
		˼·��ȷ������������
*/
class Solution {
public:
	bool helper(string& s, int i, int j, int count) {
		//���i��j����Ȳ����Ѿ�ɾ����һ��Ԫ��
		if (s[i] != s[j] && count == 0) {
			return false;
		}

		while (i <= j) {
			if (s[i] == s[j]) {
				i++;
				j--;
			}
			else {
				//����Ļ��ͽ���ɾ����ǰ��Ļ��ߺ���ģ�����ֻ��ɾ��һ��
				count = 0;
				return helper(s, i, j - 1, count) || helper(s, i + 1, j, count);
			}
		}
		return true;
	}
	bool validPalindrome(string s) {
		int i = 0, j = s.length() - 1;
		int count = 1;
		return helper(s, i, j, count);
	}
};