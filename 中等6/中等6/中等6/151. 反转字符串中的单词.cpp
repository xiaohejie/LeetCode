#include<iostream>
#include<stack>
using namespace std;
/*
	151. ��ת�ַ����еĵ���
*/
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;
        int index = 0;
        int n = s.length();
        //ɾ��ǰ���ո�
        while (s[index] == ' ') {
            index++;
        }
        //ɾ��β��ո�
        while (s[n - 1] == ' ') {
            n--;
        }
        //cout << index << " " << n ; 
        //cout << s.substr(index, n - index) << endl;
        int i = index;
        for (; i < n; i++) {
            if (s[i] == ' ') {
                //�ҵ����ַ����Ϳ�ʼ��ȡ�ַ���
                st.push(s.substr(index, i - index));
                //��ȡ���֮���ƶ�����һ�����ǿ��ַ����±�λ��
                while (s[i + 1] == ' ') {
                    i++;
                }
                index = i + 1;
            }
        }
        st.push(s.substr(index, n - index));
        while (!st.empty()) {
            ans += st.top() + ' ';
            st.pop();
        }
        return ans.substr(0, ans.size() - 1);
    }
};