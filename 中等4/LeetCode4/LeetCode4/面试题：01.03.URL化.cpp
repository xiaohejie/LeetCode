#include<iostream>
using namespace std;
/*
	 面试题 01.03. URL化
	 从后往前
		不适用额外空间（因为题目中说了字符串尾部有足够的空间存放新增字符）

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
		//截取字符串（从lenFact + 1截取到最后）
		S = S.substr(lenFact + 1);
		return S;
	}
};