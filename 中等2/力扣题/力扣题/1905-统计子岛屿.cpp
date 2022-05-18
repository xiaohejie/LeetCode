#include<iostream>
#include<vector>
using namespace std;
/*
	ͳ���ӵ��죺
		��grid1�в��ǵ���ĵ���grid2���ǵ���ĵط���ɺ��󣨰����������ڵĵط���
*/
class Solution {
public:
	void dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
		//��ֹ����
		if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
			return;
		}

		grid[i][j] = 0;

		dfs(grid, m, n, i+1, j);
		dfs(grid, m, n, i-1, j);
		dfs(grid, m, n, i, j+1);
		dfs(grid, m, n, i, j-1);
	}
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		int m = grid1.size(), n = grid1[0].size();
		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid1[i][j] == 0 && grid2[i][j] == 1) {
					dfs(grid2, m, n, i, j);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid2[i][j] == 1) {
					count++;
					dfs(grid2, m, n, i, j);
				}
			}
		}
		return count;
	}
};