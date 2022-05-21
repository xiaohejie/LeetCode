#include<iostream>
#include<vector>
using namespace std;
/*
	不同路径III（与岛屿题类似，可以一起看）：
		使用回溯法
*/
class Solution {
public:
	int m = 0, n = 0;
	int res = 0;
	void dfs(int i, int j, int emptySquares, vector<vector<int>>& grid) {
		/*中止条件（函数和列数、该点为障碍点、该点已经走过）*/
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == -2) {
			return;
		}
		/*已经到达结束点*/
		if (grid[i][j] == 2) {
			/*已经的到达结束点，并且所有的空点已经走过*/
			if (emptySquares == -1) {
				res++;
			}
			return;
		}
		/*否则的话，就是更新该点，并上下左右进行遍历*/
		grid[i][j] = -2;
		dfs(i+1, j, emptySquares-1, grid);
		dfs(i-1, j, emptySquares-1, grid);
		dfs(i, j+1, emptySquares-1, grid);
		dfs(i, j-1, emptySquares-1, grid);

		/*进行回溯*/
		grid[i][j] = 0;
		//回溯的时候，emptySquares不需要进行改变（这个很重要，我不太懂）
	}
	int uniquePathsIII(vector<vector<int>>& grid) {
		m = grid.size();		//行数
		n = grid[0].size();		//列数
		int emptySquares = 0;	//空的点数
		/*查找空的点数*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					emptySquares++;
				}
			}
		}
		/*查找起点，开始dfs*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					//开始走
					dfs(i, j, emptySquares, grid);
				}
			}
		}
		return res;
	}
};