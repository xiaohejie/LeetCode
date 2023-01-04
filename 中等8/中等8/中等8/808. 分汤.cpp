#include<iostream>
#include<vector>
using namespace std;
/*
	808. 分汤
        动态规划
*/
class Solution {
public:
    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        //创建动态容器，d[i][j]表示汤A和汤B分别剩下i和j份时所求的概率值，即汤A先分配完的概率+汤A和汤B同时分配完的概率除以2
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        //初始化动态容器
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            //汤A先分配完的概率
            dp[0][i] = 1.0;
        }
        //状态转换方程
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] + dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
            }
        }
        return dp[n][n];
    }
};