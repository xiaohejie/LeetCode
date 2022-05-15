#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	N皇后问题：（回溯法求解）
		
*/
class Solution {
public:
	vector<vector<string>> res;				//答案
	void generateResult(vector<vector<bool>>& board) {
		vector<string> rs;
		for (int i = 0; i < board.size(); i++) {
			string ans = "";
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j]) {
					ans += 'Q';
				}
				else {
					ans += '.';
				}
			}
			rs.push_back(ans);
		}
		res.push_back(rs);
	}
	void dfs(int i, int n, vector<vector<bool>>& board, unordered_set<int>& col, unordered_set<int>& pie, unordered_set<int>& na) {
		//回溯中止条件（i==n表示已经到达末尾）
		if (i == n) {
			generateResult(board);		//记录答案
			return;
		}
		//遍历列
		for (int j = 0; j < n; j++) {
			if (col.count(j) || pie.count(i+j) || na.count(i-j)) {
				//判断那些地方不可以取
				continue;
			}
			board[i][j] = true;		//记录当前board[i][j]已选中
			//更新那些点不可取
			col.insert(j);
			pie.insert(i + j);
			na.insert(i - j);

			//跳转到下一行
			dfs(i + 1, n, board, col, pie, na);

			//进行回溯（撤销当前选取的点）
			board[i][j] = false;
			col.erase(j);
			pie.erase(i + j);
			na.erase(i - j);
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n, 0));				//记录选中的位置
		unordered_set<int> col, pie, na;		//有哪些位置不可以再选
		//进行回溯
		dfs(0, n, board, col, pie, na);		//从第0行开始，n行n列，选中的位置，不可选的位置 
		return res;
	}
};