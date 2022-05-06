#include<iostream>
#include<vector>
using namespace std;
/*
	螺旋矩阵II：
		
*/

class Solution {
public:
	int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };		//定义方向矩阵
	vector<vector<int>> generateMatrix(int n) {
		int num = n * n;
		vector<vector<bool>> visited(n, vector<bool>(n, 0));		//记录该点是否已经访问过(可以不需要这个矩阵，因为当res[i][j]部位0时，就说明已经访问过)
		vector<vector<int>> res(n, vector<int>(n));
		int dirIndex = 0;				//定义方向，先向左
		int row = 0, col = 0;			//实时更新行和列
		for (int i = 0; i < num; i++) {	
			res[row][col] = i + 1;
			visited[row][col] = true;
			//判断下一个点，是否合理
			int newRow = row + directions[dirIndex][0], newCol = col + directions[dirIndex][1];
			if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || visited[newRow][newCol]) {
				//不合理的话需要旋转方向
				dirIndex = (dirIndex + 1) % 4;
			}
			//更新下一个点
			row += directions[dirIndex][0];
			col += directions[dirIndex][1];
		}
		return res;
	}
};