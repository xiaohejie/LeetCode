#include<iostream>
#include<vector>
using namespace std;
/*
	�����ַ���ƥ�䣺
		ʹ��̰�Ĳ��ԣ�
		��s[0] == 'I'ʱ������res[0] == '0';
		��s[0] == 'D'ʱ������res[0] == 'n'
		��������0��n��
*/
class Solution {
public:
	vector<int> diStringMatch(string s) {
		int n = s.length();
		int minNum = 0, maxNum = n;
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'I') {
				//����Ҫ����Сֵ�Ž�ȥ
				res[i] = minNum;
				minNum++;
				cout << res[i] << ",";
			}
			else if (s[i] == 'D') {
				res[i] = maxNum;
				cout << res[i] << ";";
				maxNum--;
			}
		}
		res.push_back(maxNum);
		return res;
	}
};