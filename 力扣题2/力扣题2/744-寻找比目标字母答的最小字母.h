#pragma once
#include<iostream>
#include <vector>
using namespace std;
/*
    给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。
    另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

        在比较时，字母是依序循环出现的。举个例子：
        如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'

*/
class Solution744 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        for (auto& ch : letters) {
            if (ch <= target) {
                continue;
            }
            else {
                ans = ch;
                return ans;
            }
        }
        return letters[0];      //没有比他大的返回第一个字母
    }
};
