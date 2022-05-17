#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
    字符间最短的距离：
        需要判断前面和后面有没有
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int len = s.length();
        int minDis = INT_MAX;
        for (int i = 0; i < len; i++) {
            //遍历s中的每个元素
            for (int j = 0; j < len; j++) {
                if (s[j] == c) {
                    minDis = min(minDis, abs(i-j));
                }
            }
            ans.push_back(minDis);
            minDis = INT_MAX;
        }
    }
};

/*
    验证外星语字典
*/
class Solution {
public:
    //验证两个单词是否符合（判断第一个不相同的）
    unordered_map<char, int> map;
    bool helper(string s1, string s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            cout << map.at(s1[i]) << " " << map.at(s2[i]) << endl;
            if (s1[i] != s2[i]) {
                if (map.at(s1[i]) > map.at(s2[i])) {
                    //说明不符合 
                    return false;
                }
                break;  
            }
        }
        //到最后都没判断出，就比较长短
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) {
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            map.emplace(order[i], i);
        }
        for (int i = 1; i < words.size(); i++) {
            bool isAcc = helper(words[i-1], words[i]);
            if (!isAcc) {
                return false;
            }
        }
        return true;
    }
};
