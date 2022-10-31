#include<iostream>
#include<vector>
using namespace std;
/*
	115. ��ͬ��������
        ��̬�滮
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (!n || !m) return !n ? 0 : 1;
        //�����ά���飺��ʾt��ǰj���ַ�������sǰi���ַ�����ɵ�������
        s = ' ' + s, t = ' ' + t;
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        //���г�ʼ������sΪ�գ����0��Ϊ0����tΪ�գ����0��Ϊ1
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        //״̬ת�Ʒ���
        /*
            s[i] == t[j]�� ˵��dp[i][j] = dp[i-1][j-1] + dp[i - 1][j];
            s[i] != t[j]�� ˵��dp[i][j] = dp[ - 1][j];
        */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};