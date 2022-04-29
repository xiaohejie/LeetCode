#include<iostream>
using namespace std;
/*
	验证回文字符串：
		思路正确，代码有问题
*/
class Solution {
public:
	bool helper(string& s, int i, int j, int count) {
		//如果i和j不相等并且已经删除过一个元素
		if (s[i] != s[j] && count == 0) {
			return false;
		}

		while (i <= j) {
			if (s[i] == s[j]) {
				i++;
				j--;
			}
			else {
				//否则的话就进行删除（前面的或者后面的），且只能删除一次
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