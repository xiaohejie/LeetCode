#include<iostream>
#include<vector>
using namespace std;
/*
	��С·���ͣ�
		ʹ��DP�㷨
*/
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		//������̬����
		vector<vector<int>> dp(m, vector<int>(n, 0));
		//��ʼ��
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			dp[i][0] = dp[i - 1][0] + grid[i][0];
			cout << dp[i][0] << " ";
		}
		cout << endl;
		for (int j = 1; j < n; j++) {
			dp[0][j] = dp[0][j - 1] + grid[0][j];
			cout << dp[0][j] << " ";
		}
		//״̬ת�Ʒ���
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				int res1 = dp[i][j - 1] + grid[i][j];
				int res2 = dp[i - 1][j] + grid[i][j];
				dp[i][j] = min(res1, res2);
			}
		}
		return dp[m - 1][n - 1];
	}
};