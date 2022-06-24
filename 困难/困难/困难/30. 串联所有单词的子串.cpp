#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	30. �������е��ʵ��Ӵ�
        ά��һ���������ڣ���֤�����ڵĵ�����ȫƥ��words
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) {
            return ans;
        }
        
        int n = s.length(), m = words.size(), w = words[0].length();
        //��¼Ŀ�괮��ÿ�����ʳ��ֵĴ���
        unordered_map<string, int> total;
        for (int i = 0; i < m; i++) {
            total[words[i]]++;
        }

        //��������
        for (int i = 0; i < w; i++) {
            unordered_map<string, int> window;
            int cnt = 0;
            //���±�i���л������ڵ��ƶ�
            for (int j = i; j + w <= n; j += w) {
                //����Ŀ�괮���ȣ���Ҫȥ��ͷ�����ַ���
                if (j >= i + m * w) {
                    string word = s.substr(j - m * w, w);
                    window[word]--;
                    //������º�ĵ�������С����Ҫ�ĵ���������˵������һ����Ч����
                    if (window[word] < total[word]) {
                        cnt--;
                    }
                }
                //�����������
                string word = s.substr(j, w);
                window[word]++;
                //�����Ӻ󵥴�������������Ч����������˵����һ����Ч����
                if (window[word] <= total[word]) {
                    cnt++;
                }

                //���cnt == m����˵����ȫƥ�䣬��ӽ��
                if (cnt == m) {
                    ans.push_back(j - (m - 1) * w);
                }
            }
        }
        return ans;
    }
};