#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
    ɾ�����������ţ�
        �ҵ�ÿ����֧��Ȼ��ɾ������ߺ����ұߵ�����
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> vec;
        string ans = "";
        int countL = 0, countR = 0;
        int pre = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                countL++;
            }
            if (s[i] == ')') {
                countR++;
            }
            if (countL == countR) {
                //���н�ȡ
                string res = s.substr(pre, i - pre + 1);
                vec.push_back(res);
                countL = countR = 0;
                pre = i + 1;
            }
        }
        //ȥ�����������
        for (auto& s : vec) {
            int len = s.size();
            s = s.substr(1, len - 2);
            /*s.erase(0, 1);
            s.erase(len - 2, 1);*/
            ans += s;
        }
        return ans;
    }
};