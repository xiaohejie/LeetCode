#include<iostream>
using namespace std;
/*
	926-将字符串翻转到单调递增
        使用动态规划
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;       //设初始值，表示第i个位置为0或1的最小翻转次数
        for (auto& ch : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (ch == '1') {
                dp0New++;
            }
            else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};