#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
	467. �����ַ�����Ψһ�����ַ���:
		ʹ�ö�̬�滮
*/
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> dp(26);
		int k = 0;
		for (int i = 0; i < p.length(); i++) {
			if (i > 0 && (p[i] - p[i-1] + 26 ) % 26 == 1) {			//�ַ�ֻ��Ϊ1����Ϊ25
				++k;
			}
			else {
				k = 1;
			}
			//��Ľ�β
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};