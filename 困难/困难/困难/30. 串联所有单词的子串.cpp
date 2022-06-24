#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	30. 串联所有单词的子串
        维护一个滑动窗口，保证窗口内的单词完全匹配words
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) {
            return ans;
        }
        
        int n = s.length(), m = words.size(), w = words[0].length();
        //记录目标串中每个单词出现的次数
        unordered_map<string, int> total;
        for (int i = 0; i < m; i++) {
            total[words[i]]++;
        }

        //滑动窗口
        for (int i = 0; i < w; i++) {
            unordered_map<string, int> window;
            int cnt = 0;
            //从下标i进行滑动窗口的移动
            for (int j = i; j + w <= n; j += w) {
                //超过目标串长度，需要去除头部的字符串
                if (j >= i + m * w) {
                    string word = s.substr(j - m * w, w);
                    window[word]--;
                    //如果更新后的单词数量小于需要的单词数量，说明这是一个有效单词
                    if (window[word] < total[word]) {
                        cnt--;
                    }
                }
                //添加新增单词
                string word = s.substr(j, w);
                window[word]++;
                //如果添加后单词数量不超过有效单词数，就说明是一个有效单词
                if (window[word] <= total[word]) {
                    cnt++;
                }

                //如果cnt == m，就说明完全匹配，添加结果
                if (cnt == m) {
                    ans.push_back(j - (m - 1) * w);
                }
            }
        }
        return ans;
    }
};