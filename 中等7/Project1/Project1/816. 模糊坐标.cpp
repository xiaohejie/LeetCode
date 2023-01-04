#include<iostream>
#include<vector>
using namespace std;
/*
	816. ģ������
*/
class Solution {
    vector<string> getPos(string s) {
        vector<string> pos;
        //�����ַ����ĵ�0���ַ���Ϊ0���߸����ַ���Ϊ��0��������Խ������ַ���ֱ�ӷ���pos��
        if (s[0] != '0' || s == "0") {
            pos.push_back(s);
        }
        //�����ַ��ʹ��ĵ�1���ַ���ʼ����������С���㻮��
        for (int p = 1; p < s.size(); p++) {
            //����±겻Ϊ1�������ַ����ĵ�0���±�Ϊ0������Ҫ��������Ϊ������0��Ϊ��ͷ��
            //�������һ���ַ��ǡ�0����Ҳ��Ҫ������С���������0��
            if ((p != 1 && s[0] == '0') || s.back() == '0') {
                continue;
            }
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size() - 2;
        vector<string> res;
        s = s.substr(1, s.size() - 2);
        for (int l = 1; l < n; l++) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;
            vector<string> rt = getPos(s.substr(l));
            if (rt.empty()) continue;
            //ѭ����ϱ���
            for (auto& i : lt) {
                for (auto& j : rt) {
                    res.push_back("(" + i + "," + j + ")");
                }
            }
        }
        return res;
    }
};