#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
	946. 验证栈序列
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            //先将pushed进行入栈
            st.push(pushed[i]);
            //如果栈中不为空，并且栈顶元素等于poped[j]，说明可以出栈
            while (!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            //否则的话就将pushed中的元素继续加入栈中
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};