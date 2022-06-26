#include<iostream>
#include<vector>
using namespace std;
/*
	剑指 Offer II 091. 粉刷房子
        n皇后的简化版本
        回溯法（更简单的方法试试用动态规划）
*/
//使用回溯法有问题，我也找不出来
/*
class Solution {
    int row = 0, col = 0;
    int minCost = INT_MAX;
public:
    void backTrack(vector<vector<int>>& costs, int nowRow, int nowCol, int row, int col, int cost) {
        if (nowRow == row) {
            //遍历结束
            minCost = min(minCost, cost);
            return;
        }
        if (nowCol == col) {
            //说明已经遍历到列尾
            nowCol = 0;
        }
        //遍历
        for (int i = nowCol; i < col; i++) {
            cost += costs[nowRow][nowCol];
            backTrack(costs, nowRow+1, nowCol+1, row, col, cost);
            cost -= costs[nowRow][nowCol];
        }
    }
    int minCost(vector<vector<int>>& costs) {
        row = costs.size(), col = costs[0].size();
        int cost = 0;
        backTrack(costs, 0, 0, row, col, cost);
    }
};*/

//使用动态规划
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        //创建初始动态容器，进行初始化
        vector<int> dp(3);
        for (int i = 0; i < 3; i++) {
            dp[i] = costs[0][i];
        }

        //状态转移方程（从第一个房子开始）
        for (int i = 1; i < n; i++) {
            //剩余动态容器
            vector<int> dpNew(3);
            //这个房子选择三种颜色的花费
            for (int j = 0; j < 3; j++) {
                dpNew[j] = min(dp[(j + 1)%3], dp[(j + 2) % 3]) + costs[i][j];
            }
            dp = dpNew;
        }
        //找到最小值
        int minV = INT_MAX;
        for (int i = 0; i < 3; i++) {
            minV = min(minV, dp[i]);
        }
        return minV;
    }
};