#include<iostream>
#include<vector>
using namespace std;
/*
	623. 在二叉树中增加一行
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
	vector<TreeNode*> ans;
	void helper(TreeNode* root, int depth, int curDepth) {
		if (root == nullptr) {
			return;
		}
		if (curDepth == depth - 1) {
			ans.push_back(root);
			return;
		}
		curDepth++;
		helper(root->left, depth, curDepth);
		helper(root->right, depth, curDepth);
	}
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		if (depth == 1) {
			TreeNode* node = new TreeNode(val);
			node->left = root;
			return node;
		}
		helper(root, depth, 1);
		for (auto a : ans) {
			TreeNode* lnode = new TreeNode(val);
			TreeNode* rnode = new TreeNode(val);
			//需要记录原来的子树
			TreeNode* lTemp = a->left;
			TreeNode* rTemp = a->right;
			a->left = lnode;
			a->right = rnode;
			lnode->left = lTemp;
			rnode->right = rTemp;
		}
		return root;
	}
};