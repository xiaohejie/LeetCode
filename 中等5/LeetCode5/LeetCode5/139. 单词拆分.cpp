#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	139. 单词拆分（有点绕，画图）
        动态规划
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        s = ' ' + s;            //添加空格以便处理边界
        vector<bool> f(n + 1);      //表示字符串前i个字符能否被字典中的若干个字符串表示
        f[0] = 1;
        unordered_set<string> set;
        for (auto& word : wordDict) {
            set.insert(word);
        }

        for (int i = 1; i <= n; i++) {
            //需要s前面的字符串能够被表示，然后在
            for (int j = 1; j <= i; j++) {
                if (f[j - 1] && set.find(s.substr(j, i - j + 1)) != set.end()) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n];
    }
};