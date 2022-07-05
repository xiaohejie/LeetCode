#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	522. ��������� II
        ��Ŀ����������⣺����һ���ַ������飬�������ҳ��ַ������㵱ǰ�ַ��������ַ��������������ַ����������У����������������ַ����� ����ַ����ĳ���
        ���������ַ����Ƿ�����һ���ַ��������ַ���
        ˫����������ж�
*/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        //ʹ��lambda���ʽ���ж�s�Ƿ���t���Ӵ�
        auto is_subaeq = [](const string& s, const string& t)-> bool {
            int pt_s = 0, pt_t = 0;
            while (pt_s < s.size() && pt_t < t.size()) {
                if (s[pt_s] == t[pt_t]) {
                    pt_s++;
                }
                pt_t++;
            }
            return pt_s == s.size();        //����ȣ���˵��s��t�������У����ȣ���˵�����ǡ�
        }; 
        int len = strs.size();
        int ans = -1;
        for (int i = 0; i < len; i++) {
            bool check = true;      //��¼���������
            //����ٽ���һ��forѭ���������۲�strs[i]�ǲ��������ַ�����������
            for (int j = 0; j < len; j++) {
                if (i != j && is_subaeq(strs[i], strs[j])) {
                    //strs[i]��strs[j]��������
                    check = false;
                    break;
                }
            }
            if (check) {
                //˵��strs[i]����û�������ַ�����������
                int ilen = strs[i].size();
                ans = max(ans, ilen);
            }
        }
        return ans;
    }
};