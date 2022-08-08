#include<iostream>
#include<vector>
using namespace std;
/*
	814. 二叉树剪枝
		使用递归
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
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		//使用递归
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		//如果
		if (root->left == nullptr && root->right == nullptr && root->val == 0) {
			return nullptr;
		}
		return root;
	}
};