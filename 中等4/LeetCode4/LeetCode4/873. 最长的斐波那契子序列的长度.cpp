#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	873. 最长的斐波那契子序列的长度
        使用动态规划：
            需要使用二维数组dp：以arr[i]和arr[j]结尾的最长斐波那契字数列的长度
            一维数组进行dp不满足，会忽略连接处的斐波那契数列数列要求
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int>nMap;
        int len = arr.size();
        //创建动态容器
        vector<vector<int>> dp(len, vector<int>(len, 2));
        for (int i = 0; i < len; i++) {
            //用于后续得到idx(arr[i]-arr[j])
            nMap[arr[i]] = i;
            //遍历所有可能的j
            for (int j = i - 1; j >= 0; j--) {
                //计算差值dif
                int dif = arr[i] - arr[j];
                //如果差值比arr[j]大，说明找过头了，就直接退出
                if (dif >= arr[j]) {
                    break;
                }
                //否则的话，看dif在不在arr中，如果在的话进行状态转移
                if (dif < arr[j] && nMap.find(dif) != nMap.end()) {
                    //需要确定dp[i][j]的最大值
                    dp[i][j] = max(dp[j][nMap[dif]] + 1, dp[i][j]);
                    //更新ans
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        //如果最后ans == 2，那么说明没有斐波那契数列，因为斐波那契数列的最小长度是3
        return ans == 2 ? 0 : ans;
    }
};