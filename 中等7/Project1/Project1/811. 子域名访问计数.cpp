#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	811. 子域名访问计数
        先使用哈希表
*/
class Solution {
public:
    void helper(string str, unordered_map<string, int>& map) {
        int count = 0;
        int i = 0;
        while (str[i] != ' ') {
            i++;
        }
        count = atoi(str.substr(0, i).c_str()); //得到该域名被访问了所少次
        str = str.substr(i + 1);
        int j = 0, index = 0;
        while (j != str.length()) {
            while (str[j] != '.') {
                if (j >= str.length()) {
                    break;
                }
                j++;
            }
            if (j >= str.length()) {
                break;
            }
            map[str.substr(index)] += count;
            j++;
            index = j;
        }
        map[str.substr(j)] += count;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> map;
        for (int i = 0; i < cpdomains.size(); i++) {
            helper(cpdomains[i], map);
        }
        //转化为字符串
        for (auto& m : map) {
            string s = to_string(m.second);
            s += m.first;
            ans.push_back(s);
        }
        return ans;
    }
};