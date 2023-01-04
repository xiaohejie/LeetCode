#include<iostream>
#include<vector>
using namespace std;
/*
	809. ��зḻ������
    ˫ָ��
*/
class Solution {
    bool helper(string s, string word) {
        //�ж��ַ���s���ַ���word�ܲ���ƥ��
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            //��������ַ����ȣ���ֱ���˳�
            if (s[i] != word[j]) {
                return false;
            }
            //�����ַ����
            char ch = s[i];
            int cnti = 0;
            while (i < s.size() && s[i] == ch) {    //����i�����ж��ٸ��ַ���s[i]���
                cnti++;
                i++;
            }
            int cntj = 0;
            while (j < word.size() && word[j] == ch) {  //����j�����ж��ٸ��ַ���s[i]���
                cntj++;
                j++;
            }
            //�����ж�
            if (cnti < cntj) {
                return false;
            }
            if (cnti != cntj && cnti < 3) {
                return false;
            }
        }
        //��Ҫ�жϵ����������i == s.size() && j == word.size();
        return i == s.size() && j == word.size();
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto& word : words) {
            if (helper(s, word)) {
                ans++;
            }
        }
        return ans;
    }
};