#include<iostream>
#include<vector>
using namespace std;
/*
	螺旋矩阵：
		先列方向数组（左，下， 右，上）
		建立数组（判断是否已经访问过）
		计算当前数组中一共有多少个元素（遍历到count时，就说明已经完成）
		for(int i = 0; i <count; i++){
			res.push_back(num[i]);		
			visited[col][row] = true;
			//判断下一个点，是否合理
			if(<0 || >= cols || <0 || >= rows || isVisited){
				//不合理，就要移动到下一个方向
				dirIdx = (dirIdx + 1) % 4;
			}
			//正式更新当前点
		}
*/
class Solution {
public:
	int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };		//方向：依次左，下，右，上
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return res;
		}
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<bool>> visited(rows, vector<bool>(cols, 0));		//记录是否已经访问过该点
		int numCount = rows * cols;		//得到一共有多少个数字
		int row = 0, col = 0;
		int dirIdx = 0;					//记录当前位置,初始值是向左
		for (int i = 0; i < numCount; i++) {
			res.push_back(matrix[row][col]);
			visited[row][col] = 1;		//记录已经访问过
			//判断下一个点，是否符合条件
			int newRow = row + directions[dirIdx][0], newCol = col + directions[dirIdx][1];
			if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol]) {
				//行列是否产出范围，是否已经访问过
				//如果访问过。就要更新dirInx
				dirIdx = (dirIdx + 1) % 4;		//%4主要是到4的时候其实是0
			}
			//正式更新当前点
			row += directions[dirIdx][0];
			col += directions[dirIdx][1];
		}
		return res;
	}
};
