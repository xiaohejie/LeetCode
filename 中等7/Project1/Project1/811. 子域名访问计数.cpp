#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	811. ���������ʼ���
        ��ʹ�ù�ϣ��
*/
class Solution {
public:
    void helper(string str, unordered_map<string, int>& map) {
        int count = 0;
        int i = 0;
        while (str[i] != ' ') {
            i++;
        }
        count = atoi(str.substr(0, i).c_str()); //�õ������������������ٴ�
        str = str.substr(i + 1);
        int j = 0, index = 0;
        while (j != str.length()) {
            while (str[j] != '.') {
                if (j >= str.length()) {
                    break;
                }
                j++;
            }
            if (j >= str.length()) {
                break;
            }
            map[str.substr(index)] += count;
            j++;
            index = j;
        }
        map[str.substr(j)] += count;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> map;
        for (int i = 0; i < cpdomains.size(); i++) {
            helper(cpdomains[i], map);
        }
        //ת��Ϊ�ַ���
        for (auto& m : map) {
            string s = to_string(m.second);
            s += m.first;
            ans.push_back(s);
        }
        return ans;
    }
};