#include<iostream>
#include<vector>
using namespace std;
/*
	208. ʵ�� Trie (ǰ׺��)
*/
class Trie {
    vector<Trie*> children;
    bool isEnd;
    //ǰ׺ƥ��
    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
public:
    //��ʼ��ǰ׺������26���������Ƿ�ΪҶ�ӽ��
    Trie() : children(26), isEnd(false) {

    }
    //����
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    //����
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    //�ж�ǰ׺
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};