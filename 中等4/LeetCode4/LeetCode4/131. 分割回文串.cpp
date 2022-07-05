#include<iostream>
#include<vector>
using namespace std;
/*
	131. 分割回文串
*/
class Solution {
    int len;
    vector<vector<bool>> f;    
    vector<vector<string>> ans;
    vector<string> path;
public:
    //回溯（字符串s，当前下标）
    void dfs(string s, int index) {
        //中止条件
        if (index == s.length()) {
            ans.push_back(path);
            return;
        }
        //从当前位置找我们构成的回文字符串
        for (int i = index; i < s.length(); i++) {
            if (f[index][i] == 0) {
                continue;
            }
            //否则的话，构成回文字符串 
            path.push_back(s.substr(index, s.length() - i + 1 ));
            //进行下一个位置的dfs
            dfs(s, i+1);
            //恢复现场
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        len = s.length();       //计算字符串长度
        //初始化
        f = vector<vector<bool>>(len, vector<bool>(len));
        //状态转移方程（因为要确保f[i+1, j-1]已经遍历，所以从列开始遍历）
        //f[i, j] = (s[i] == s[j])&&f[i+1, j-1]
        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    f[i][j] = 1;

                }
                else {
                    //否则的话，f[i, j] = (s[i] == s[j])&&f[i+1, j-1]
                    f[i][j] = (s[i] == s[j]) && (i+1 > j-1 || f[i + 1][j - 1]);
                }
            }
        }
        dfs(s, 0);
        return ans;
    }
};