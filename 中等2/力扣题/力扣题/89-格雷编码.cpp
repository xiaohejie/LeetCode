#include<iostream>
#include<vector>
using namespace std;
/*
	格雷编码：
		找规律，理解
*/
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		while (n--) {
			for (int i = ans.size() - 1; i >= 0; --i) {
				//从最后一位开始移动
				ans[i] <<= 1;
				//然后把左移后的数字加1放入ans中
				ans.push_back(ans[i] + 1);
			}
		}
		return ans;
	}
};