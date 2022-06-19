#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	105-��ǰ���������������й��������
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
	//������¼��������ڵ���±�
	unordered_map<int, int> map;
public:
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr || il > ir) {
			return nullptr;
		}
		//������¼��preorder[pl]Ϊ���ڵ�������������ж��ٸ��ڵ�
		int k = map[preorder[pl]] - il;
		//����ڵ�
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
		//���������
		return build(preorder, inorder, 0, len - 1, 0, len - 1);
	}
};