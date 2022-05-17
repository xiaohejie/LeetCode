#include<iostream>
#include<stack>
#include<string>
#include <sstream> 
#include<vector>
using namespace std;
/*
	简化路径：
		可以使用栈
*/
class Solution {
public:
	string simplifyPath(string path) {
		stack<string> stk;
		stringstream ss(path);
		string item;
		while (getline(ss, item, '/')) {
			if (item == "..") {
				if (!stk.empty()) {
					stk.pop();
				}
				else if (item != "." && item != "") {
					stk.push(item);
				}
			}
		}
		string ans;
		//要反过来加
		while (!stk.empty()) {
			ans = "/" + stk.top() + ans;
			stk.top();
		}
		return ans.empty() ? "/" : ans;
	}
};