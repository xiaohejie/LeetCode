#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	两颗二叉树中的所有元素：
		1、先遍历两颗二叉树
		2、在对二叉树进行排序添加
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
private:
	vector<int> tree1;
	vector<int> tree2;
public:
	//进行先序遍历
	void helper(TreeNode* root, vector<int>& tree) {
		if (root == NULL) {
			return;
		}
		tree.push_back(root->val);
		helper(root->left, tree);
		helper(root->right, tree);
	}
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		helper(root1, tree1);
		helper(root2, tree2);
		//直接合并，再进行排序
		for (int i = 0; i < tree2.size(); i++) {
			tree1.push_back(tree2[i]);
		}
		sort(tree1.begin(), tree1.end());
		return tree1;
	}
};