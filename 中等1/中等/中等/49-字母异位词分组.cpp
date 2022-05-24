#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
using namespace std;
/*
	字母异位词分组：
		思路：每个字母异位词经过排序后得到的key是一样的
        利用unordered_map将排序后为key的字符串放到一起
        最后将map->second放入到vector<vector<string>>ans中
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        //对每个字符串进行排序，用unordered_map存放每个字符串以及排序后的字符串
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            ans[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& k : ans) {
            res.push_back(k.second);
        }
        return res;
    }
};