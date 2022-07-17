#include<iostream>
#include<vector>
using namespace std;
/*
	676. ʵ��һ��ħ���ֵ�
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
        //ö��words�е�ÿһ������
        for (auto& word : words) {
            //���Ȳ���
            if (word.size() != searchWord.size()) {
                continue;
            }
            //������ȡ��ж������м����ַ���һ��
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