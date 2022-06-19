#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	105-从前序和中序遍历序列中构造二叉树
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
	//用来记录中序遍历节点的下标
	unordered_map<int, int> map;
public:
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		//用来记录以preorder[pl]为根节点的数的左子树有多少个节点
		int k = map[preorder[pl]] - il;
		//构造节点
		TreeNode* root = new TreeNode(preorder[pl]);
		root->left = build(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
		root->right = build(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		for (int i = 0; i < len; i++) {
			map[inorder[i]] = i;
		}
		//构造二叉树
		return build(preorder, inorder, 0, len - 1, 0, len - 1);
	}
};