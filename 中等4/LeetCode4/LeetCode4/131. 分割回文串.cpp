#include<iostream>
#include<vector>
using namespace std;
/*
	131. �ָ���Ĵ�
*/
class Solution {
    int len;
    vector<vector<bool>> f;    
    vector<vector<string>> ans;
    vector<string> path;
public:
    //���ݣ��ַ���s����ǰ�±꣩
    void dfs(string s, int index) {
        //��ֹ����
        if (index == s.length()) {
            ans.push_back(path);
            return;
        }
        //�ӵ�ǰλ�������ǹ��ɵĻ����ַ���
        for (int i = index; i < s.length(); i++) {
            if (f[index][i] == 0) {
                continue;
            }
            //����Ļ������ɻ����ַ��� 
            path.push_back(s.substr(index, s.length() - i + 1 ));
            //������һ��λ�õ�dfs
            dfs(s, i+1);
            //�ָ��ֳ�
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        len = s.length();       //�����ַ�������
        //��ʼ��
        f = vector<vector<bool>>(len, vector<bool>(len));
        //״̬ת�Ʒ��̣���ΪҪȷ��f[i+1, j-1]�Ѿ����������Դ��п�ʼ������
        //f[i, j] = (s[i] == s[j])&&f[i+1, j-1]
        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    f[i][j] = 1;

                }
                else {
                    //����Ļ���f[i, j] = (s[i] == s[j])&&f[i+1, j-1]
                    f[i][j] = (s[i] == s[j]) && (i+1 > j-1 || f[i + 1][j - 1]);
                }
            }
        }
        dfs(s, 0);
        return ans;
    }
};