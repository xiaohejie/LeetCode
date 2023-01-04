#include<iostream>
#include<vector>
using namespace std;
/*
	813. 最大平均值和的分组
    动态规划
    dp[i][j]表示nums在区间[0，i-1]被切成j个子数组的最大平均值和
    {
        j = 1，dp[i][j]就是对应区间[0,i-1]的平均值
        j > 1，我们可以将区间[0, i-1]分成[0, x-1]和[x, i-1]两个部分，其中x >= j-1，那么dp[i][j]等于所有这些合法的切分方式的平均值和的最大值
    }
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];        //nums求和
        }
        //创建动态容器
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        //初始化动态方程
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;       //dp[i][j]表示nums在区间[0，i-1]被切成j个子数组的最大平均值和
        }
        //状态转换方程
        for (int j = 2; j <= k; j++) {
            for (int i = j; i <= n; i++) {      //因为i必须要大于等于j，所以i从j开始遍历
                for (int x = j - 1; x < i; x++) {   //x >= j-1
                    //dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x)表示：前x个数被切分成j-1个最大平均值和 + 从x到i-1的num的平均值和
                    //在遍历x进行最大比较
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};