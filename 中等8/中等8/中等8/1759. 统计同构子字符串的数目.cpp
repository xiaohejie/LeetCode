#include<iostream>
#include<unordered_map>
using namespace std;
/*
	1759. ͳ��ͬ�����ַ�������Ŀ
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
            //����ͬ���ַ����ķ�ʽ
            ans += 1ll * (num + 1) * num / 2;
            ans %= mod;
        }
        return ans;
    }
};

//����ֳ�ʱ����
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
                //�ж����ַ����Ƿ���������
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