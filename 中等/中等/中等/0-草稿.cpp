#include<iostream>
#include<vector>
using namespace std;
/*
    �ַ�����̵ľ��룺
        ��Ҫ�ж�ǰ��ͺ�����û��
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int len = s.length();
        int minDis = INT_MAX;
        for (int i = 0; i < len; i++) {
            //����s�е�ÿ��Ԫ��
            for (int j = 0; j < len; j++) {
                if (s[j] == c) {
                    minDis = min(minDis, abs(i-j));
                }
            }
            ans.push_back(minDis);
            minDis = INT_MAX;
        }
    }
};
