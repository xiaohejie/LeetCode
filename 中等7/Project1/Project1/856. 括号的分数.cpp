#include<iostream>
#include<stack>
using namespace std;
/*
	856. 括号的分数
        利用栈思想和括号匹配的思想
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);     //表示空字符串的分数
        for (auto& c : s) {
            if (c == '(') {
                //表示需要计算左括号内部字符串A的分数
                //先压入分数0，表示A前面的空字符串的分数
                st.push(0);
            }
            else {
                //右括号，表示内部A的分数已经计算出来了
                //将它弹出栈，并保存到变量v中，如果v = 0，说明字符串A是空串，分数为1，否则(A)的分数为2*A，最后将(A)的分数加到栈顶元素上
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};