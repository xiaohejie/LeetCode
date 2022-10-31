#include<iostream>
#include<vector>
using namespace std;
/*
	784. 字母大小写全排列
        使用DFS
*/
class Solution {
    void dfs(string s, vector<string>& ans, int len, int index) {
        if (index == len) { 
            ans.push_back(s);
            return;
        }
        //可以不改变当前数字，直接进入下轮
        dfs(s, ans, len, index+1);
        if (s[index] >= 'A') {
            //若当前字符为字母，也可以将当前字符替换大小写之后在进入下轮
            s[index] ^= 32;
            dfs(s, ans, len, index+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int len = s.length(); 
        dfs(s, ans, len, 0);
        return ans;
    }
};