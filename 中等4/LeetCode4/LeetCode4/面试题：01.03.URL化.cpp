#include<iostream>
using namespace std;
/*
	 ������ 01.03. URL��
	 �Ӻ���ǰ
		�����ö���ռ䣨��Ϊ��Ŀ��˵���ַ���β�����㹻�Ŀռ��������ַ���

*/
class Solution {
public:
	string replaceSpaces(string S, int length) {
		int lenFact = S.size() - 1;
		for (int i = length - 1; i >= 0; i--) {
			if (S[i] == ' ') {
				S[lenFact] = '0';
				S[lenFact - 1] = '2';
				S[lenFact - 2] = '%';
				lenFact -= 3;
			}
			else {
				S[lenFact] = S[i];
				lenFact--;
			}
		}
		//��ȡ�ַ�������lenFact + 1��ȡ�����
		S = S.substr(lenFact + 1);
		return S;
	}
};