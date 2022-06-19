#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	508-出现次数最多的子树元素和
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	unordered_map<int, int> ans;
	int maxCount = 0;
public:
	//进行深度优先遍历
	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		//计算子树和
		int sum = root->val + dfs(root->left) + dfs(root->right);
		//更新子树和出现最多次数
		maxCount = max(maxCount, ++ans[sum]);
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		dfs(root);
		vector<int> res;
		for (auto& [s, i] : ans) {
			if (i == maxCount) {
				res.push_back(s);
			}
		}
		return res;
	}
};