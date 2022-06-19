#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	890-查找和替换模式
        构造双射（需要使用两次映射）
        word 的每个字母需要映射到pattern 的对应字母，
        并且pattern 的每个字母也需要映射到word 的对应字母

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
            //判断两次映射
            if (match(word, pattern) && match(pattern, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};






//有问题
//class Solution {
//    vector<string> ans;
//    unordered_map<string, string> map;
//public:
//    //将字符串格式进行转换
//    void helper(string word) {
//        string str = "A";
//        for (int i = 1; i < word.length(); i++) {
//            if (word[i] == word[i-1]) {
//                //表示前后两个字符相等
//                str += str[i - 1];
//            }
//            //发现第i个单词与前面i-2和单词有重复的
//            string s = word.substr(0, i-1);
//            if (s.find(word[i])) {
//                str += 'A';
//            }
//            //否则的话，就在前面的基础上加一
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
//                //表示前后两个字符相等
//                pt += pt[i - 1];
//            }
//            //否则的话，就在前面的基础上加一
//            pt += (pt[i - 1] - 'A') + 1 + 'A';
//        }
//        //得到map后，与pattern进行比较
//        for (auto& m : map) {
//            if (m.second == pt) {
//                ans.push_back(m.first);
//            }
//        }
//        return ans;
//    }
//};