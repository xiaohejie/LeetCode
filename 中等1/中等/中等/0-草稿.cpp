#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
    �ַ�����̵ľ��룺
        ��Ҫ�ж�ǰ��ͺ�����û��
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int len = s.length();
        int minDis = INT_MAX;
        for (int i = 0; i < len; i++) {
            //����s�е�ÿ��Ԫ��
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
    ��֤�������ֵ�
*/
class Solution {
public:
    //��֤���������Ƿ���ϣ��жϵ�һ������ͬ�ģ�
    unordered_map<char, int> map;
    bool helper(string s1, string s2) {
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            cout << map.at(s1[i]) << " " << map.at(s2[i]) << endl;
            if (s1[i] != s2[i]) {
                if (map.at(s1[i]) > map.at(s2[i])) {
                    //˵�������� 
                    return false;
                }
                break;  
            }
        }
        //�����û�жϳ����ͱȽϳ���
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
