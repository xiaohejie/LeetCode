#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
    828. 统计子串中的唯一字符
        数学原理题
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, vector<int>> index;
        //记录每个字符在该字符串中出现的位置
        for (int i = 0; i < s.length(); i++) {
            index[s[i]].push_back(i);
        }
        int res = 0;
        for (auto&&[_, arr] : index) {
            //在头和尾进行插入，是因为什么（看解析：爪哇缪斯）
            arr.insert(arr.begin(), -1);
            arr.push_back(s.size());

            for (int i = 1; i < arr.size() - 1; i++) {
                res += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
        }
        return res;
    }
};