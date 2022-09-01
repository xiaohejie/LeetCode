#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
	946. ��֤ջ����
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            //�Ƚ�pushed������ջ
            st.push(pushed[i]);
            //���ջ�в�Ϊ�գ�����ջ��Ԫ�ص���poped[j]��˵�����Գ�ջ
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            //����Ļ��ͽ�pushed�е�Ԫ�ؼ�������ջ��
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};