#include<iostream>
using namespace std;
/*
	998. 最大二叉树 II
		要么是根节点要么是在右子树上
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
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		TreeNode* node = new TreeNode(val);
		TreeNode* parent = nullptr;
		TreeNode* cur = root;
		while (cur) {
			if (cur->val < val) {
				if (!parent) {
					//如果父节点为空，表示cur为根节点
					return new TreeNode(val, root, nullptr);
				}
				//否则的话，表明不是根节点
				//cur是node的左子树，parent的右子树是node
				parent->right = node;
				node->left = cur;
				return root;
			}
			else {
				//cur的值大于val
				//继续遍历
				parent = cur;
				cur = cur->right;
			}
		}
		//如果到最后还没有返回的话，就让当前parent的右节点指向node
		parent->right = node;
		return root;
	}
};