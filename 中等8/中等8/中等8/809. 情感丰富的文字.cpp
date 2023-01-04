#include<iostream>
#include<vector>
using namespace std;
/*
	809. 情感丰富的文字
    双指针
*/
class Solution {
    bool helper(string s, string word) {
        //判断字符串s和字符串word能不能匹配
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            //如果两个字符不等，就直接退出
            if (s[i] != word[j]) {
                return false;
            }
            //两个字符相等
            char ch = s[i];
            int cnti = 0;
            while (i < s.size() && s[i] == ch) {    //计算i后面有多少个字符与s[i]相等
                cnti++;
                i++;
            }
            int cntj = 0;
            while (j < word.size() && word[j] == ch) {  //计算j后面有多少个字符与s[i]相等
                cntj++;
                j++;
            }
            //进行判断
            if (cnti < cntj) {
                return false;
            }
            if (cnti != cntj && cnti < 3) {
                return false;
            }
        }
        //需要判断到最后，所以用i == s.size() && j == word.size();
        return i == s.size() && j == word.size();
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto& word : words) {
            if (helper(s, word)) {
                ans++;
            }
        }
        return ans;
    }
};