#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	648. 单词替换
*/
class Solution {
public:
    //将字符串进行分割
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
    //遍历每个单词从头开始的子串
    string helper(string s, vector<string>& dictionary) {
        for (int i = 0; i < s.size(); i++) {
            if (find(dictionary.begin(), dictionary.end(), s.substr(0, i + 1)) != dictionary.end()) {
                //说明已找到
                return s.substr(0, i + 1);
            }
        }
        //如果找到最后够没有找到
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        vector<string> str;
        strFen(sentence, str);      //得到分割后的单词
        //遍历单词
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

 