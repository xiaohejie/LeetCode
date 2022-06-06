#include<iostream>
#include<vector>
using namespace std;
/*
	91-���뷽����
		��̬�滮
*/
class Solution {
public:
	int numDecodings(string s) {
		//�����ַ���
		int n = s.length();
		s = ' ' + s;
		vector<int> f(n + 1);
		f[0] = 1;		//���ַ���
		for (int i = 1; i <= n; i++) {
			int a = s[i] - '0';
			int b = (s[i - 1] - '0') * 10 + a;
			if (a >0 && a<10) {
				f[i] += f[i - 1];
			}
			if (b >= 10 && b <= 26) {
				f[i] += f[i - 1];
			}
		}
		return f[n + 1];
	}
};
