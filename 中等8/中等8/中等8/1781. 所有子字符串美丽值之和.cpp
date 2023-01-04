#include<iostream>
#include<vector>
using namespace std;
/*
	1781. 所有子字符串美丽值之和
    1、求出字符串的所有子串
    2、计算每个子串的美丽值
*/
class Solution {
    int help(string s) {
        vector<int> vec(26);
        int minAns = INT_MAX;
        int maxAns = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            vec[s[i] - 'a']++;
        }
        //求出最大和最小
        for (int i = 0; i < 26; i++) {
            if (vec[i] > 0) {
                minAns = min(minAns, vec[i]);
            }
            maxAns = max(minAns, vec[i]);
        }
    }
public:
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                maxFreq = max(maxFreq, cnt[s[j] - 'a']);
                int minFreq = s.size();
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        minFreq = min(minFreq, cnt[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }
        return res;
    }
};