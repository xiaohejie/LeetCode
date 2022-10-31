#include<iostream>
using namespace std;
/*
	921. 使括号有效的最少添加
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int len = s.size();
        int leftCount = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                leftCount++;
            }
            else {
                //否则的话就是右括号
                if (leftCount > 0) {
                    //判断前面是否含有左括号
                    leftCount--;
                }
                else {
                    ans++;
                }
            }
        }
        //最后还剩多少个左括号，就说明要补充多少个右括号
        ans += leftCount;
        return ans;
    }
};