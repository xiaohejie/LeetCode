#include<iostream>
#include<vector>
using namespace std;
/*
	增减字符串匹配：
		使用贪心策略：
		当s[0] == 'I'时，表明res[0] == '0';
		当s[0] == 'D'时，表明res[0] == 'n'
		遍历（从0到n）
*/
class Solution {
public:
	vector<int> diStringMatch(string s) {
		int n = s.length();
		int minNum = 0, maxNum = n;
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'I') {
				//表明要将最小值放进去
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