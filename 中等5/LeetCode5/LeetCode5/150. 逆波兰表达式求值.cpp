#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
/*
    150. �沨�����ʽ��ֵ
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
                //�������������ת��Ϊ�����Ž�ջ��
                s.push(atoi(tokens[i].c_str()));
            }
            else {
                //����Ļ����ʹ�ջ��ȡ������Ԫ�أ��������㣬Ȼ���ٷ���ջ��
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