#include<iostream>
#include <vector>
using namespace std;
/*
	最短路径II：
		
*/
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		//创建动态容器
		vector<vector<int>> dp(m, vector<int>(n, 0));
		if (m == 0 || n == 0) {
			return 0;
		}
		//进行初始化
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] == 1) {
				//表明当前有障碍，则后面所有都不能达到
				break;
			}
			dp[i][0] = 1;
		}
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 1) {
				//表明当前有障碍，则后面所有都不能达到
				break;
			}
			dp[0][j] = 1;
		}
		//状态转移方程
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					//如果当前有障碍的话，直接跳过
					continue;
				}
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};