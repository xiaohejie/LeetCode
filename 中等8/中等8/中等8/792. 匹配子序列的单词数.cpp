#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	792. ƥ�������еĵ�����
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //��¼ÿ���ַ�����Ӧ���±�
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        //���������еĵ���
        for (auto& w : words) {
            //����õ��ʵĳ��ȴ���s�ĳ��ȣ�ֱ������
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            //��¼�±�
            int p = -1;
            //���������е�ÿ���ַ�
            for (char c : w) {
                //�ҵ����ַ���s������Щ��Ӧ���±�
                auto& ps = pos[c - 'a'];
                //���ֲ��ң����±��������ҵ���һ������p���±꣨��Ϊ˳�����ң�
                auto it = upper_bound(ps.begin(), ps.end(), p);
                //û�ҵ��Ļ�˵�����ַ�������
                if (it == ps.end()) {
                    --res;
                    break;
                }
                //�ҵ��˵Ļ�������p�±�
                p = *it;
            }
        }
        return res;
    }
};