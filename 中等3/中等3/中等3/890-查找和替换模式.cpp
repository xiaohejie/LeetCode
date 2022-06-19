#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	890-���Һ��滻ģʽ
        ����˫�䣨��Ҫʹ������ӳ�䣩
        word ��ÿ����ĸ��Ҫӳ�䵽pattern �Ķ�Ӧ��ĸ��
        ����pattern ��ÿ����ĸҲ��Ҫӳ�䵽word �Ķ�Ӧ��ĸ

*/
class Solution {
public:
    bool match(string word, string pattern) {
        unordered_map<char, char> map;
        for (int i = 0; i < word.length(); i++) {
            char x = word[i], y = pattern[i];
            if (!map.count(x)) {
                map[x] = y;  
            }
            else if (map[x] != y) {
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto& word : words) {
            //�ж�����ӳ��
            if (match(word, pattern) && match(pattern, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};






//������
//class Solution {
//    vector<string> ans;
//    unordered_map<string, string> map;
//public:
//    //���ַ�����ʽ����ת��
//    void helper(string word) {
//        string str = "A";
//        for (int i = 1; i < word.length(); i++) {
//            if (word[i] == word[i-1]) {
//                //��ʾǰ�������ַ����
//                str += str[i - 1];
//            }
//            //���ֵ�i��������ǰ��i-2�͵������ظ���
//            string s = word.substr(0, i-1);
//            if (s.find(word[i])) {
//                str += 'A';
//            }
//            //����Ļ�������ǰ��Ļ����ϼ�һ
//            str += (str[i - 1] - 'A') + 1 + 'A';
//        }
//        map[word] = str;
//    }
//    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//        for (auto& word : words) {
//            helper(word);
//        }
//        string pt = "A";
//        for (int i = 1; i < pattern.length(); i++) {
//            if (pattern[i] == pattern[i - 1]) {
//                //��ʾǰ�������ַ����
//                pt += pt[i - 1];
//            }
//            //����Ļ�������ǰ��Ļ����ϼ�һ
//            pt += (pt[i - 1] - 'A') + 1 + 'A';
//        }
//        //�õ�map����pattern���бȽ�
//        for (auto& m : map) {
//            if (m.second == pt) {
//                ans.push_back(m.first);
//            }
//        }
//        return ans;
//    }
//};