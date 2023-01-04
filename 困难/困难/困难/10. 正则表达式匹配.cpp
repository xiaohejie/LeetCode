#include<iostream>
#include<vector>
using namespace std;
/*
	10. ������ʽƥ��
        ʹ�ö�̬�滮����ƥ��
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        s = ' ' + s;
        p = ' ' + p;
        //������̬����
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));

        //��ʼ����̬����
        f[0][0] = true;

        //״̬ת������
        //s == ""   p = ".*"
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                //���j + 1 �� "*"�Ļ�������������ΪҪ��p[j]��p[j+1]һ��Ƚ�
                if (j + 1 <= n && p[j + 1] == '*') continue;
                if (p[j] != '*') {
                    f[i][j] = i && j && f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else {
                    f[i][j] = (j >= 2 && f[i][j - 2]) || (i && j && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return f[m][n];
    }
};