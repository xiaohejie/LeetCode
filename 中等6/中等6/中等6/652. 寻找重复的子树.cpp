#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	652. 寻找重复的子树
		使用序列化（序列化一棵二叉树参考剑指offer37 序列化二叉树）
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
	unordered_map<string, int> map;
	vector<TreeNode*> ans;
public:
	string dfs(TreeNode* root) {
		if (root == nullptr) {
			return "";
		}
		string ss = to_string(root->val) + "(" + dfs(root->left) + ")" + "(" + dfs(root->right) + ")";
		map[ss]++;
		if (map[ss] == 2) {
			ans.push_back(root);
		}
		return ss;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return ans;
	}
};