#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	438. 找到字符串中所有字母异位词
*/
class Solution {
    vector<int> ans;
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return ans;
        }
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) {
            ans.push_back(0);
        }
        for (int i = 0; i < sLen - pLen; i++) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];
            if (sCount == pCount) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};


class Solution {
    //该方法会超出时间限制
    vector< int> ans;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
public:
    void helper(string s, string p) {
        int len = p.size();
        int i = 0, j = len;
        while (j <= s.size()) {
            string str = s.substr(i, j - i);
            m2.clear();
            for (int m = 0; m < str.size(); m++) {
                m2[str[m]]++;
            }
            cout << endl;
            //判断m1和m2是否相等
            bool flag = 1;
            for (int m = 0; m < p.size(); m++) {
                if (m1[p[m]] != m2[p[m]]) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                ans.push_back(i);
            }
            i++;
            j++;
        }
    }
    vector<int> findAnagrams(string s, string p) {
        for (int i = 0; i < p.size(); i++) {
            m1[p[i]]++;
        }
        helper(s, p);
        return ans;
    }
};