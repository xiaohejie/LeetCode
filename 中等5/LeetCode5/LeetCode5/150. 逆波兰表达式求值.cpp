#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
/*
    150. 逆波兰表达式求值
*/
class Solution {
    stack<int> s;
    bool isNumber(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            return false;
        }
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (isNumber(tokens[i])) {
                //如果是整数，就转化为整数放进栈中
                s.push(atoi(tokens[i].c_str()));
            }
            else {
                //否则的话，就从栈中取出两个元素，进行运算，然后再放入栈中
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    s.push(num1 + num2);
                }
                else if (tokens[i] == "-") {
                    s.push(num1 - num2);
                }
                else if(tokens[i] == "*") {
                    s.push(num1 * num2);
                }
                else if (tokens[i] == "/") {
                    s.push(num1 / num2);
                }
            }
        }
        return s.top();
    }
};