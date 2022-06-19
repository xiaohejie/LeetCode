#include<iostream>
#include<vector>
using namespace std;
/*
	97-�����ַ���
        ��̬�滮
        s1[i]��ʾ��0��i������s2[j]��ʾ��0��j����
        s3[i+j]��ʾ��0��i+j����
        ��s3[i+j] = s1[i]����f[i, j] = f[i-1, j];
        ��s3[i+j] = s2[j]����f[i, j] = f[i, j-1];
        ����f[i, j] = f[i-1, j] || f[i, j-1];
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        int t = s3.size();
        //����ַ���s1�ĳ��ȼ����ַ���s2�ĳ��Ȳ�����s3�ĳ��ȣ��ͷ���false;
        if (m + n != t) {
            return false;
        }
        //����ʹ�ö�̬�滮
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        //�����ʼ״̬
        f[0][0] = true;

        
        // ������ڿ�ʼ��λ�ü���0
        s1 += ' ', s2 += ' ', s3 += ' ';
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i != 0 && s1[i] == s3[i + j]) {
                    //���һ������s[i]����
                    f[i][j] = f[i - 1][j];
                }
                if (j != 0 && s2[j] == s3[i + j]) {
                    f[i][j] = f[i][j] || f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};