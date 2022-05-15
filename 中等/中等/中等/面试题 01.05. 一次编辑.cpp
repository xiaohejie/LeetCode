#include<iostream>
using namespace std;
/*
	һ�α༭��
		
*/
class Solution {
public:
	bool oneEditAway(string first, string second) {
		int len1 = first.length();
		int len2 = second.length();
		//�������������2����ֱ�ӷ���false
		if (len1 == len2) {
			//�ж���ȵ�����£��ܲ���ͨ���滻��ʹ�������
			int count = 0;
			for (int i = 0; i < len1; i++) {
				if (first[i] != second[i]) {
					count++;		//��¼�ַ����в���ȵ��ַ�
					if (count > 1) {
						return false;
					}
				}
			}
			return true;
		}
		else if ((len1-len2) == 1) {
			//first���ȴ���second���������1������£��ܲ���ͨ�������ɾ��һ���ַ�
			int i = 0, j = 0;
			while (i < len1 && j < len2) {
				if (first[i] == second[j]) {
					i++;
					j++;
				}
				else {
					i++;
				}
				if (i - j >= 2) {
					return false;
				}
			}
			return true;
		}
		else if ((len2-len1) == 1) {
			//first����С��second���������1������£��ܲ���ͨ�������ɾ��һ���ַ�
			int i = 0, j = 0;
			while (i < len1 && j < len2) {
				if (first[i] == second[j]) {
					i++;
					j++;
				}
				else {
					j++;
				}
				if (j - i >= 2) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
};