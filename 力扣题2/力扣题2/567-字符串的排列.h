#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
/*
	567-字符串的排列：
        给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。
            如果是，返回 true ；否则，返回 false 。

        换句话说，s1 的排列之一是 s2 的 子串 。
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int lenS1 = s1.length(), lenS2 = s2.length();
        if (lenS1 > lenS2) {
            return false;
        }
        vector<int> S1(26), S2(26);
        for (int i = 0; i < lenS1; i++) {
            ++S1[s1[i] - 'a'];
            ++S2[s2[i] - 'a'];
        }
        if (S1 == S2) {
            return true;
        }
        for (int i = lenS1; i < lenS2; i++) {
            ++S2[s2[i] - 'a'];
            --S2[s2[i - lenS1] - 'a'];
            if (S1 == S2) {
                return true;
            }
        }
        return false;
    }
    //unordered_map<char, int> countS1;
    //unordered_map<char, int> countS2;
    ////计算各个字母的个数
    //void counter(string s, unordered_map<char, int>& count) {
    //    for (auto& ch : s) {
    //        ++count[ch];
    //    }
    //}
    //bool checkInclusion(string s1, string s2) {
    //    int len1 = s1.length();
    //    int len2 = s2.length();
    //    if (len1 > len2) {
    //        return false;
    //    }
    //    //计算S1中各个字符的个数
    //    counter(s1, countS1);
    //    //使用滑动窗口，计算S2
    //    for (int i = 0; i + len1 < len2; i++ ) {
    //        counter(s2.substr(), countS2);      //得到与S1长度相等的字符串中各个字符的个数
    //        if (countS1 == countS2) {
    //            return true;
    //        }
    //    }
    //    return false;
    //}
};