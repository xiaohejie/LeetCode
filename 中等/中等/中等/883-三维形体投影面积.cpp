#include<iostream>
#include <vector>
using namespace std;
/*
	三维形体投影面积：
		xy 平面的投影面积等于网格上非零数值的数目；
		yz 平面的投影面积等于网格上每一列最大数值之和；
		zx 平面的投影面积等于网格上每一行最大数值之和。
*/
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int len = grid.size();
		int xyArea = 0, yzArea = 0, zxArea = 0;
		for (int i = 0; i < len; i++) {
			int yzHeight = 0, zxHeight = 0;
			for (int j = 0; j < len; j++) {
				xyArea += grid[i][j] > 0 ? 1 : 0;
				yzHeight = max(grid[j][i], yzHeight);
				zxHeight = max(grid[i][j], zxHeight);
			}
			yzArea += yzHeight;
			zxArea += zxHeight;
		}
		return xyArea + yzArea + zxArea;
	}
};