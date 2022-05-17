#include<iostream>
#include<vector>
#include <unordered_set>
#include<string>
using namespace std;
/*
	有效的数独：
		思路1：暴力求解：把每个数所在行、列、单元格都求出来
						用unordered_set进行判断
*/
class Solution {
private:
	unordered_set<string> set;
public:
	//判断unordered_set有没有该字符串
	bool helper(unordered_set<string>& set, string s) {
		if (set.find(s) == set.end()) {
			set.insert(s);
			return true;
		}
		else {
			return false;
		}
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') {
					continue;	//如果不是数字跳过
				}
				//数字单元格
				int boxIndex = i / 3 * 3 + j / 3;
				//否则的话将所在行、列、单元格求出
				string r = to_string(board[i][j]) + "in row" + to_string(i);				//该数字所在行
				string c = to_string(board[i][j]) + "in cow" + to_string(j);				//该数字所在列
				string idx = to_string(board[i][j]) + "int box" + to_string(boxIndex);		//该数字所在单元格
				bool res = helper(set, r) && helper(set, c) && helper(set, idx);
				if (!res)
				{
					return false;
				}
			}
		}
		return true;
	}
};