#include<iostream>
using namespace std;
/*
	669. 修剪二叉搜索树
		使用迭代
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
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return nullptr;
		}
		//如该节点的值小于low，说明该节点以及该节点的左子树都不符合要求
		if (root->val < low) {
			//我们就需要遍历该节点的右子树
			return trimBST(root->right, low, high);
		}
		else if (root->val > high) {
			//如果该节点的值大于high，说明该节点以及该节点的右子树都需要修剪
			//返回该节点的右子树
			return trimBST(root->left, low, high);
		}
		else {
			//说明该节点在[low, high]的范围中
			//该节点保留，继续遍历它的左子树和右子树
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}
	}
};