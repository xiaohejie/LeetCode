#include<iostream>
#include<vector>
using namespace std;
/*
	513. 找树左下角的值
		采用深度优先遍历
		因为我们先遍历左子树，然后再遍历右子树，所以对同一高度的所有节点，最左节点肯定是最先被遍历到的。
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
		//进行深度优先搜索
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

/*通过调试观察*/
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
