#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	139. ���ʲ�֣��е��ƣ���ͼ��
        ��̬�滮
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        s = ' ' + s;            //��ӿո��Ա㴦��߽�
        vector<bool> f(n + 1);      //��ʾ�ַ���ǰi���ַ��ܷ��ֵ��е����ɸ��ַ�����ʾ
        f[0] = 1;
        unordered_set<string> set;
        for (auto& word : wordDict) {
            set.insert(word);
        }

        for (int i = 1; i <= n; i++) {
            //��Ҫsǰ����ַ����ܹ�����ʾ��Ȼ����
            for (int j = 1; j <= i; j++) {
                if (f[j - 1] && set.find(s.substr(j, i - j + 1)) != set.end()) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n];
    }
};