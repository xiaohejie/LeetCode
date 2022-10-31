#include<iostream>
#include<vector>
using namespace std;
/*
	784. ��ĸ��Сдȫ����
        ʹ��DFS
*/
class Solution {
    void dfs(string s, vector<string>& ans, int len, int index) {
        if (index == len) { 
            ans.push_back(s);
            return;
        }
        //���Բ��ı䵱ǰ���֣�ֱ�ӽ�������
        dfs(s, ans, len, index+1);
        if (s[index] >= 'A') {
            //����ǰ�ַ�Ϊ��ĸ��Ҳ���Խ���ǰ�ַ��滻��Сд֮���ڽ�������
            s[index] ^= 32;
            dfs(s, ans, len, index+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int len = s.length(); 
        dfs(s, ans, len, 0);
        return ans;
    }
};