#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	791. 自定义字符串排序
*/
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        //记录字符在order中的位置
        for (int i = 0; i < order.size(); i++) {
            val[order[i] - 'a'] = i + 1;
        }
        //在s中进行排序
        sort(s.begin(), s.end(), [&](char& c1, char& c2) {
            return val[c1 - 'a'] < val[c2 - 'a'];
            });
        return s;
    }
};