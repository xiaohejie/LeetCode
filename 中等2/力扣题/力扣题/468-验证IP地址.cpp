#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
	验证IP地址：

*/
class Solution {
public:
    //编写两个函数，判断是否符合IP规则
    bool isIPV4(vector<string> s) {
        cout << s.size() << endl;
        if (s.size() != 4) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            cout << s[i].size() << endl;
            if (s[i].size() > 1 && s[i][0] == '0') {
                cout << s[i] << "  ";
                return false;
            }
            if (s[i].size() > 3) {
                return false;
            }
            //判断是否是范围之内
            for (int j = 0; j < s[i].length(); j++) {
                if (!(s[i][j] - '0' >= 0 && s[i][j] - '0' <= 9)) {
                    return false;
                }
            }
            if (stoi(s[i]) < 0 || stoi(s[i]) > 255) {
                //cout << stoi(s[i]) << "  ";
                return false;
            }
        }
        return true;
    }
    bool isIPV6(vector<string> s) {
        if (s.size() != 8) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            //每个子串的长度1-4
            if (s[i].size() < 1 || s[i].size() > 4) {
                return false;
            }
            //子串是十六进制字符串
            for (int j = 0; j < s[i].size(); j++) {
                if (!((s[i][j] - '0' >= 0 && s[i][j] - '0' <= 9) || (s[i][j] - 'a' >= 0 && s[i][j] - 'a' <= 5) || (s[i][j] - 'A' >= 0 && s[i][j] - 'A' <= 5))) {
                    return false;
                }
            }
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        if (queryIP == "") {
            return "Neither";
        }
        if (queryIP[queryIP.size() - 1] == '.' || queryIP[queryIP.size() - 1] == '.') {
            return "Neither";
        }
        //先查找包含“.”还是“:”
        vector<string> vec;
        if (queryIP.find('.') != -1) {
            int idx = 0, i = 0;
            //判断是否是IPv4
            queryIP += '.';
            //截取字符串
            while (i < queryIP.length())
            {
                if (queryIP[i] == '.' && queryIP[i + 1] == '.') {
                    return "Neither";
                }
                if (queryIP[i] == '.') {
                    //截取字符串
                    cout << queryIP.substr(idx, i - idx) << endl;
                    vec.push_back(queryIP.substr(idx, i - idx));
                    idx = i + 1;
                }
                i++;
            }
            //进行判断
            if (isIPV4(vec)) {
                return "IPv4";
            }
        }
        else if (queryIP.find(':') != -1) {
            int idx = 0, i = 0;
            //判断是否是IPv6
            queryIP += ':';
            //截取字符串
            while (i < queryIP.length())
            {
                if (queryIP[i] == ':' && queryIP[i + 1] == ':') {
                    return "Neither";
                }
                if (queryIP[i] == ':') {
                    //截取字符串
                    // cout << queryIP.substr(idx, i - idx) << endl;
                    vec.push_back(queryIP.substr(idx, i - idx));
                    idx = i + 1;
                }
                i++;
            }
            //进行判断
            if (isIPV6(vec)) {
                return "IPv6";
            }
        }
        return "Neither";
    }
};