#include<iostream>
#include<vector>
using namespace std;
/*
	删列造序：（傻逼题目描述有问题）
		（1）判断该字符串是不是按字典序升序进行排列(这尼玛的是字符串，想多了)
		（2）for循环{
			得到结果
		}
*/
class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int row = strs.size();
		int col = strs[0].size();
		int count = 0;
		for (int j = 0; j < col; j++) {
			for (int i = 1; i < row; i++) {
				if (strs[i][j] < strs[i-1][j]) {
					count++;
					break;
				}
			}
		}
		return count;
	}
};