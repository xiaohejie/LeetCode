#include<iostream>
#include<vector>
using namespace std;
/*
	208. 实现 Trie (前缀树)
*/
class Trie {
    vector<Trie*> children;
    bool isEnd;
    //前缀匹配
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
    //初始化前缀树对象，26个子树，是否为叶子结点
    Trie() : children(26), isEnd(false) {

    }
    //插入
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
    //查找
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }
    //判断前缀
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};