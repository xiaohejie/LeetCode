#include<iostream>
#include<vector>
using namespace std;
/*
	97-交错字符串
        动态规划
        s1[i]表示从0到i个数，s2[j]表示从0到j个数
        s3[i+j]表示从0到i+j个数
        若s3[i+j] = s1[i]，则f[i, j] = f[i-1, j];
        若s3[i+j] = s2[j]，则f[i, j] = f[i, j-1];
        所以f[i, j] = f[i-1, j] || f[i, j-1];
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        int t = s3.size();
        //如果字符串s1的长度加上字符串s2的长度不等于s3的长度，就返回false;
        if (m + n != t) {
            return false;
        }
        //下面使用动态规划
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        //定义初始状态
        f[0][0] = true;

        
        // 这边是在开始的位置加上0
        s1 += ' ', s2 += ' ', s3 += ' ';
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i != 0 && s1[i] == s3[i + j]) {
                    //最后一个数是s[i]，则
                    f[i][j] = f[i - 1][j];
                }
                if (j != 0 && s2[j] == s3[i + j]) {
                    f[i][j] = f[i][j] || f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};