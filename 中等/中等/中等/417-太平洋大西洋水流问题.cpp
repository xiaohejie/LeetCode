#include<iostream>
#include<vector>
using namespace std;
/*
	太平洋大西洋水流问题：
		思路：
			1、从左边缘开始dfs所有能流通到太平洋的的大陆板块，从右边缘大陆板块开始dfs所有能流通到大西洋的大陆板块
			2、从上边缘开始dfs所有能流通到太平洋的的大陆板块，从下边缘大陆板块开始dfs所有能流通到大西洋的大陆板块
			然后进行dfs判断
*/
class Solution {
	/*
		思路是对的，但有问题
	*/
private:
	int directions[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };			//方向
	int row = 0, col = 0;				//行数和列数	
	vector<vector<int>> heights;		//创建全局数组
public:
	//深度优先搜索
	//void dfs(int i, int j, vector<vector<bool>> canReach) {
	//	if (canReach[i][j]) {
	//		return;
	//	}
	//	canReach[i][j] = true;	//未访问过进行标记
	//	//然后访问上下左右
	//	for (auto d : directions) {
	//		int nextR = i + d[0];
	//		int nextC = j + d[1]; 
	//		//如果dfs的新节点位置越界了或者其高度没有前序节点高度高
	//		if (nextR < 0 || nextR > row || nextC < 0 || nextC >col || heights[i][j] > heights[nextR][nextC]) {
	//			continue;
	//		}
	//		//否则的话进行递归调用
	//		dfs(nextR, nextC, canReach);
	//	}
	//}
	void dfs(int row, int col, vector<vector<bool>>& ocean) {
		int m = ocean.size();
		int n = ocean[0].size();
		if (ocean[row][col]) {
			return;
		}
		ocean[row][col] = true;
		for (int i = 0; i < 4; i++) {
			int newRow = row + directions[i][0], newCol = col + directions[i][1];
			if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && heights[newRow][newCol] >= heights[row][col]) {
				dfs(newRow, newCol, ocean);
			}
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		this->heights = heights;
		vector<vector<int>> res;
		/*if (heights.size() == 0) {
			return res;
		}*/
		row = heights.size();
		col = heights[0].size();
		vector<vector<bool>> canReachPacific(row, vector<bool> (col, false));
		vector<vector<bool>> canReachAtlantic(row, vector<bool>(col, false));
		
		//从左边缘开始dfs所有能流通到太平洋的的大陆板块，从右边缘大陆板块开始dfs所有能流通到大西洋的大陆板块
		for (int i = 0; i < row; i++) {
			dfs(i, 0, canReachPacific);
			dfs(i, col - 1, canReachAtlantic);
		}
		//从上边缘开始dfs所有能流通到太平洋的的大陆板块，从下边缘大陆板块开始dfs所有能流通到大西洋的大陆板块
		for (int j = 0; j < col; j++) {
			dfs(0, j, canReachPacific);
			dfs(row - 1, j, canReachAtlantic);
		}

		//遍历所有的板块把既能流通到太平洋又能流通到大西洋的板块进行添加
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
					res.push_back({ i, j });
				}
			}
		}
		return res;
	}
};