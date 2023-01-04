#include<iostream>
#include<vector>
using namespace std;
/*
	10. 正则表达式匹配
        使用动态规划进行匹配
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        s = ' ' + s;
        p = ' ' + p;
        //创建动态容器
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));

        //初始化动态容器
        f[0][0] = true;

        //状态转换方程
        //s == ""   p = ".*"
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //如果j + 1 是 "*"的话，就跳过，因为要将p[j]与p[j+1]一起比较
                if (j + 1 <= n && p[j + 1] == '*') continue;
                if (p[j] != '*') {
                    f[i][j] = i && j && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else {
                    f[i][j] = (j >= 2 && f[i][j - 2]) || (i && j && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return f[m][n];
    }
};