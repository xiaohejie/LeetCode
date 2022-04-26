#include<iostream>
#include<vector>
using namespace std;
/*
    字符间最短的距离：
        需要判断前面和后面有没有
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int len = s.length();
        int minDis = INT_MAX;
        for (int i = 0; i < len; i++) {
            //遍历s中的每个元素
            for (int j = 0; j < len; j++) {
                if (s[j] == c) {
                    minDis = min(minDis, abs(i-j));
                }
            }
            ans.push_back(minDis);
            minDis = INT_MAX;
        }
    }
};
