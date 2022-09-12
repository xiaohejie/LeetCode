#include<iostream>
using namespace std;
/*
	687. �ֵͬ·��
		ʹ��DFS
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
	int maxAns = 0;
public:
	int dfs(TreeNode* root) {
		//��ֹ����
		if (root == nullptr) {
			return 0;
		}
		int left = dfs(root->left);
		int right = dfs(root->right);
		// ����������ӽڵ�͸��ڵ�ֵͬ���������·��;�������·��Ϊ0
		if (root->left && root->val == root->left->val) {
			left++;
		}
		else {
			left = 0;
		}
		if (root->right && root->val == root->right->val) {
			right++;
		}
		else {
			right = 0;
		}

		maxAns = max(maxAns, left + right);
		return max(left, right);
	}
	int longestUnivaluePath(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		dfs(root);
		return maxAns;
	}
};