#include<iostream>
#include<unordered_map>
using namespace std;
/*
	1759. 统计同构子字符串的数目
*/

class Solution {
public:
    long long mod = 1e9 + 7;
    int countHomogenous(string s) {
        int n = s.size();
        long long ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            while (j < n && s[i] == s[j]) {
                j++;
            }
            int num = j - i;
            //计算同构字符串的方式
            ans += 1ll * (num + 1) * num / 2;
            ans %= mod;
        }
        return ans;
    }
};

//会出现超时现象
class Solution {
    bool help(string str) {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] != str[0]) {
                return false;
            }
        }
        return true;
    }
public:
    int countHomogenous(string s) {
        int n = s.length();
        long long ans = 0;
        long long mod = 1e9 + 7;
        unordered_map<string, int> map;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string str = s.substr(i, j - i + 1);
                //判断子字符串是否满足条件
                if (help(str)) {
                    map[str]++;
                }else{
                    break;
                }
            }
        }
        for (auto& m : map) {
            ans += m.second;
            ans %= mod;
        }
        return ans;
    }
};