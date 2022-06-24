#include<iostream>
#include<vector>
using namespace std;
/*
	513. �������½ǵ�ֵ
		����������ȱ���
		��Ϊ�����ȱ�����������Ȼ���ٱ��������������Զ�ͬһ�߶ȵ����нڵ㣬����ڵ�϶������ȱ��������ġ�
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
	void dfs(TreeNode* root, int height, int& maxHeight, int& value) {
		if (root == nullptr) {
			return;
		}
		height++;
		//���������������
		dfs(root->left, height, maxHeight, value);
		cout << "left" << root->val << "---" << height << endl;
		dfs(root->right, height, maxHeight, value);
		cout << "right" << root->val << "---" << height << endl;
		if (height > maxHeight) {
			maxHeight = height;
			value = root->val;
		}
	}
	int findBottomLeftValue(TreeNode* root) {
		int maxHeight = 0, value = 0;
		dfs(root, 0, maxHeight, value);

		return value;
	}
};

/*ͨ�����Թ۲�*/
//int main() {
//	TreeNode* root = new TreeNode(1);
//
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(2);
//
//	root->left->left = new TreeNode(4);
//	root->right->left = new TreeNode(5);
//	root->right->right = new TreeNode(6);
//
//	root->right->left->left = new TreeNode(7);
//
//	Solution s;
//	s.findBottomLeftValue(root);
//	return 0;
//}
