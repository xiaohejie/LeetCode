#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
	��֤IP��ַ��

*/
class Solution {
public:
    //��д�����������ж��Ƿ����IP����
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
            //�ж��Ƿ��Ƿ�Χ֮��
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
            //ÿ���Ӵ��ĳ���1-4
            if (s[i].size() < 1 || s[i].size() > 4) {
                return false;
            }
            //�Ӵ���ʮ�������ַ���
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
        //�Ȳ��Ұ�����.�����ǡ�:��
        vector<string> vec;
        if (queryIP.find('.') != -1) {
            int idx = 0, i = 0;
            //�ж��Ƿ���IPv4
            queryIP += '.';
            //��ȡ�ַ���
            while (i < queryIP.length())
            {
                if (queryIP[i] == '.' && queryIP[i + 1] == '.') {
                    return "Neither";
                }
                if (queryIP[i] == '.') {
                    //��ȡ�ַ���
                    cout << queryIP.substr(idx, i - idx) << endl;
                    vec.push_back(queryIP.substr(idx, i - idx));
                    idx = i + 1;
                }
                i++;
            }
            //�����ж�
            if (isIPV4(vec)) {
                return "IPv4";
            }
        }
        else if (queryIP.find(':') != -1) {
            int idx = 0, i = 0;
            //�ж��Ƿ���IPv6
            queryIP += ':';
            //��ȡ�ַ���
            while (i < queryIP.length())
            {
                if (queryIP[i] == ':' && queryIP[i + 1] == ':') {
                    return "Neither";
                }
                if (queryIP[i] == ':') {
                    //��ȡ�ַ���
                    // cout << queryIP.substr(idx, i - idx) << endl;
                    vec.push_back(queryIP.substr(idx, i - idx));
                    idx = i + 1;
                }
                i++;
            }
            //�����ж�
            if (isIPV6(vec)) {
                return "IPv6";
            }
        }
        return "Neither";
    }
};