#include<iostream>
#include<vector>
using namespace std;
/*
	统计封闭岛屿的数目：
		
*/
class Solution {
public:
	void dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
			return;
		}

		grid[i][j] = 1;

		dfs(grid, m, n, i-1, j);
		dfs(grid, m, n, i+1, j);
		dfs(grid, m, n, i, j-1);
		dfs(grid, m, n, i, j+1);
	}
	int closedIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int count = 0;
		//处理边界（这边很重要。理解）
		for (int i = 0; i < m; i++) {
			dfs(grid, m, n, i, 0);
			dfs(grid, m, n, i, n - 1);
		}
		for (int j = 0; j < n; j++) {
			dfs(grid, m, n, 0, j);
			dfs(grid, m, n, m - 1, j);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					count++;
					dfs(grid, m, n, i, j);
				}
			}
		}
		return count;
	}
};