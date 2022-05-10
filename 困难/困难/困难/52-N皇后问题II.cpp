#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	N皇后问题II：
		
*/
class Solution {
public:
	int num = 0;
	void DFS(int i, int n, vector<vector<bool>>& board, unordered_set<int>& col, unordered_set<int>& pie, unordered_set<int>& na) {
		//回溯中止条件
		if (i == n) {
			//要将答案更新
			num++;
			return;
		}
		//遍历列
		for (int j = 0; j < n; j++) {
			//可以进入该列的条件
			if (col.count(j) || pie.count(i+j) || na.count(i-j)) {
				continue;
			}
			//更新
			board[i][j] = true;
			col.insert(j);
			pie.insert(i + j);
			na.insert(i-j);
			
			//立即进入下一行
			DFS(i+1, n, board, col, pie, na);

			//进行回溯
			board[i][j] = false;
			col.erase(j);
			pie.erase(i + j);
			na.erase(i-j);
		}
	
	}
	int totalNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n, 0));		//记录选中的位置（即true）
		unordered_set<int> col, pie, na;
		DFS(0, n, board, col, pie, na);
		return num;
	}
};