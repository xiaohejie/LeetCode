#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	648. �����滻
*/
class Solution {
public:
    //���ַ������зָ�
    vector<string> strFen(string sentence, vector<string>& str) {
        int len = sentence.length();
        int i = 0;
        while (i <len) {
            int start = i;
            while (sentence[i] != ' ') {
                i++;
            }
            str.push_back(sentence.substr(start, i - start));
        }
    }
    //����ÿ�����ʴ�ͷ��ʼ���Ӵ�
    string helper(string s, vector<string>& dictionary) {
        for (int i = 0; i < s.size(); i++) {
            if (find(dictionary.begin(), dictionary.end(), s.substr(0, i + 1)) != dictionary.end()) {
                //˵�����ҵ�
                return s.substr(0, i + 1);
            }
        }
        //����ҵ����û���ҵ�
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        vector<string> str;
        strFen(sentence, str);      //�õ��ָ��ĵ���
        //��������
        for (int i = 0; i < str.size(); i++) {
            string s = helper(str[i], dictionary);
            ans.append(s);
            if (i != str.size() - 1) {
                ans.append(" ");
            }
        }
        return ans;
    }
};

 