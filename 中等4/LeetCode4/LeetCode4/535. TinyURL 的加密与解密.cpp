#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
/*
	535. TinyURL �ļ��������
        ʹ�ù�ϣ����д洢
*/
class Solution {
    unordered_map<int, string> map;
    int id = 0;
public:
    Solution() {
        //���캯��
        id = 0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        id++;
        map[id] = longUrl;
        return string("http://tinyurl.com/") + to_string(id);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int p = shortUrl.rfind('/') + 1;
        int key = stoi(shortUrl.substr(p, int(shortUrl.size() - p)));
        return map[key];
    }
};