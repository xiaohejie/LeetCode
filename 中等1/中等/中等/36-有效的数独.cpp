#include<iostream>
#include<vector>
#include <unordered_set>
#include<string>
using namespace std;
/*
	��Ч��������
		˼·1��������⣺��ÿ���������С��С���Ԫ�������
						��unordered_set�����ж�
*/
class Solution {
private:
	unordered_set<string> set;
public:
	//�ж�unordered_set��û�и��ַ���
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
					continue;	//���������������
				}
				//���ֵ�Ԫ��
				int boxIndex = i / 3 * 3 + j / 3;
				//����Ļ��������С��С���Ԫ�����
				string r = to_string(board[i][j]) + "in row" + to_string(i);				//������������
				string c = to_string(board[i][j]) + "in cow" + to_string(j);				//������������
				string idx = to_string(board[i][j]) + "int box" + to_string(boxIndex);		//���������ڵ�Ԫ��
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