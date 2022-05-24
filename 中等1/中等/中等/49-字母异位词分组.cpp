#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
using namespace std;
/*
	��ĸ��λ�ʷ��飺
		˼·��ÿ����ĸ��λ�ʾ��������õ���key��һ����
        ����unordered_map�������Ϊkey���ַ����ŵ�һ��
        ���map->second���뵽vector<vector<string>>ans��
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        //��ÿ���ַ�������������unordered_map���ÿ���ַ����Լ��������ַ���
        for (auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            ans[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& k : ans) {
            res.push_back(k.second);
        }
        return res;
    }
};