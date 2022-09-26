#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	187. 重复的DNA序列
        哈希加substr
        哈希+滑动窗口+位运算（没看懂）
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> ans;
        for (int i = 9; i < s.length(); i++) {
            string str = s.substr(i-9, i);
            map[str]++;
        }
        for (auto& m : map) {
            if (m.second > 1) {
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};