#include<iostream>
#include<vector>
using namespace std;
/*
	790. 多米诺和托米诺平铺
        找规律 + 动态规划
*/
class Solution {
    const long long mod = 1e9 + 7;
public:
    int numTilings(int n) {
        //创建动态容器
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        //初始化
        dp[0][3] = 1;
        //状态转移方程
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
};