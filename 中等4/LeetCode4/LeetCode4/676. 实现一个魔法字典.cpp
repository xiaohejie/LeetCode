#include<iostream>
#include<vector>
using namespace std;
/*
	676. 实现一个魔法字典
*/
class MagicDictionary {
    vector<string> words;
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }

    bool search(string searchWord) {
        //枚举words中的每一个单词
        for (auto& word : words) {
            //长度不等
            if (word.size() != searchWord.size()) {
                continue;
            }
            //长度相等。判断里面有几个字符不一样
            int count = 0;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] != searchWord[i]) {
                    count++;
                }
                if (count > 1) {
                    return false;
                }
            }
            if (count == 1) {
                return true;
            }
        }
        return false;
    }
};