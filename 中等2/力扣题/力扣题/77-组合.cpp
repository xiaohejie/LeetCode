#include<iostream>
#include<vector>
using namespace std;
/*
	��ϣ�
		����
*/
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> res;
	void dfs(int start, int n, int k) {
		//��ֹ����
		if (k == res.size()) {
			ans.push_back(res);
			return;
		}
		if(res.size() + n - start + 1 < k){
			return;
		}
	
		//���еݹ�
		for (int i = start; i <= n; i++) {
			res.push_back(i);
			dfs(i+1, n, k);
			res.pop_back();
		}
		

	}
	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}
};