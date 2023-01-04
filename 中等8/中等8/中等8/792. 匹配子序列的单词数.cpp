#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	792. 匹配子序列的单词数
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //记录每个字符所对应的下标
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        //遍历数组中的单词
        for (auto& w : words) {
            //如果该单词的长度大于s的长度，直接跳过
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            //记录下标
            int p = -1;
            //遍历单词中的每个字符
            for (char c : w) {
                //找到该字符在s中有哪些对应的下标
                auto& ps = pos[c - 'a'];
                //二分查找，在下标数组中找到第一个大于p的下标（因为顺序不能乱）
                auto it = upper_bound(ps.begin(), ps.end(), p);
                //没找到的话说明该字符不存在
                if (it == ps.end()) {
                    --res;
                    break;
                }
                //找到了的话，更新p下标
                p = *it;
            }
        }
        return res;
    }
};