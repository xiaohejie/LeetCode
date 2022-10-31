#include<iostream>
#include<stack>
using namespace std;
/*
	856. ���ŵķ���
        ����ջ˼�������ƥ���˼��
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);     //��ʾ���ַ����ķ���
        for (auto& c : s) {
            if (c == '(') {
                //��ʾ��Ҫ�����������ڲ��ַ���A�ķ���
                //��ѹ�����0����ʾAǰ��Ŀ��ַ����ķ���
                st.push(0);
            }
            else {
                //�����ţ���ʾ�ڲ�A�ķ����Ѿ����������
                //��������ջ�������浽����v�У����v = 0��˵���ַ���A�ǿմ�������Ϊ1������(A)�ķ���Ϊ2*A�����(A)�ķ����ӵ�ջ��Ԫ����
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};