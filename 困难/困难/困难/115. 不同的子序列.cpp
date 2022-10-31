#include<iostream>
#include<vector>
using namespace std;
/*
	115. 不同的子序列
        动态规划
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (!n || !m) return !n ? 0 : 1;
        //定义二维数组：表示t的前j个字符可以有s前i个字符串组成的最多个数
        s = ' ' + s, t = ' ' + t;
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        //进行初始化，若s为空，则第0列为0；若t为空，则第0行为1
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        //状态转移方程
        /*
            s[i] == t[j]， 说明dp[i][j] = dp[i-1][j-1] + dp[i - 1][j];
            s[i] != t[j]， 说明dp[i][j] = dp[ - 1][j];
        */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};