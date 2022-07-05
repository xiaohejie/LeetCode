#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	522. 最长特殊序列 II
        题目翻译的有问题：给出一个字符串数组，在里面找出字符串满足当前字符串不是字符串数组中其他字符串的子序列，返回满足条件的字符串中 最长的字符串的长度
        函数：该字符串是否是另一个字符串的子字符串
        双层遍历进行判断
*/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        //使用lambda表达式：判断s是否是t的子串
        auto is_subaeq = [](const string& s, const string& t)-> bool {
            int pt_s = 0, pt_t = 0;
            while (pt_s < s.size() && pt_t < t.size()) {
                if (s[pt_s] == t[pt_t]) {
                    pt_s++;
                }
                pt_t++;
            }
            return pt_s == s.size();        //若相等，则说明s是t的子序列，不等，则说明不是。
        }; 
        int len = strs.size();
        int ans = -1;
        for (int i = 0; i < len; i++) {
            bool check = true;      //记录最长特殊序列
            //这边再进行一次for循环是用来观察strs[i]是不是其他字符串的子序列
            for (int j = 0; j < len; j++) {
                if (i != j && is_subaeq(strs[i], strs[j])) {
                    //strs[i]是strs[j]的子序列
                    check = false;
                    break;
                }
            }
            if (check) {
                //说明strs[i]里面没有其他字符串的子序列
                int ilen = strs[i].size();
                ans = max(ans, ilen);
            }
        }
        return ans;
    }
};