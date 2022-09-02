#include<iostream>
#include<stack>
using namespace std;
/*
	151. 反转字符串中的单词
*/
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;
        int index = 0;
        int n = s.length();
        //删除前导空格
        while (s[index] == ' ') {
            index++;
        }
        //删除尾随空格
        while (s[n - 1] == ' ') {
            n--;
        }
        //cout << index << " " << n ; 
        //cout << s.substr(index, n - index) << endl;
        int i = index;
        for (; i < n; i++) {
            if (s[i] == ' ') {
                //找到空字符，就开始截取字符串
                st.push(s.substr(index, i - index));
                //截取完成之后，移动到下一个不是空字符的下标位置
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