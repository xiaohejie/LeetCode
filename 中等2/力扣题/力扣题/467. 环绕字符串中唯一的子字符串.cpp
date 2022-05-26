#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
/*
	467. 环绕字符串中唯一的子字符串:
		使用动态规划
*/
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> dp(26);
		int k = 0;
		for (int i = 0; i < p.length(); i++) {
			if (i > 0 && (p[i] - p[i-1] + 26 ) % 26 == 1) {			//字符只差为1或者为25
				++k;
			}
			else {
				k = 1;
			}
			//存的结尾
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};