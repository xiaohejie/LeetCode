#include<iostream>
#include<vector>
using namespace std;
/*
	1441. 用栈操作构建数组
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int num = 1;
        for (int i = 0; i < target.size(); i++) {
            while (num++ != target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
             ans.push_back("Push");
        }
        return ans;
    }
};