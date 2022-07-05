#include<iostream>
#include<vector>
using namespace std;
/*
	120. 三角形最小路径和
        使用动态规划    
*/
//该方法是从是上往下
class Solution {
public:
    int res = INT_MAX;
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> ans(row, vector<int>(row));
        //进行初始化
        ans[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            //每行的第一列，它的上一行没有前一列
            ans[i][0] = ans[i - 1][0] + triangle[i][0];
            //遍历每行的其余列，除最后一列
            for (int j = 1; j < i; j++) {
                ans[i][j] = min(ans[i - 1][j - 1], ans[i-1][j]) + triangle[i][j];
            }
            //最后一列，该列没有上一行
            ans[i][i] = ans[i - 1][i - 1] + triangle[i][i];
        }
        //找出最后一列的最小值
        for (int i = 0; i < row; i++) {
            res = min(res, ans[row][i]);
        }
        return res;
    }
};
//还有一种是从下往上（重要）从下往上，最后直接返回，不需要找最小值
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
        return dp[0];
    }
};