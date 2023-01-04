#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	791. �Զ����ַ�������
*/
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        //��¼�ַ���order�е�λ��
        for (int i = 0; i < order.size(); i++) {
            val[order[i] - 'a'] = i + 1;
        }
        //��s�н�������
        sort(s.begin(), s.end(), [&](char& c1, char& c2) {
            return val[c1 - 'a'] < val[c2 - 'a'];
            });
        return s;
    }
};