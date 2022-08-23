#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
	655. 输出二叉树
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
	//确定树的高度
	int findHeight(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return 1 + max(findHeight(root->left), findHeight(root->right));
	}
	//进行
	void dfs(TreeNode* root, vector<vector<string>>& ans, int r, int c, int height) {
		if (root == nullptr) {
			return;
		}
		ans[r][c] = to_string(root->val);
		cout << ans[r][c] << "-";
		if (root->left) {
			dfs(root->left, ans, r + 1, c - (1 << (height - r - 1)), height);
		}
		if (root->right) {
			dfs(root->right, ans, r + 1, c + (1 << (height - r - 1)), height);
		}
	}
	vector<vector<string>> printTree(TreeNode* root) {
		int height = findHeight(root) - 1;
		int m = height + 1, n = (1 << (height + 1)) - 1;
		cout << height << " " << m << " " << n << endl;
		//cout << height << " ";
		vector<vector<string>> ans(m, vector<string>(n, ""));
		dfs(root, ans, 0, (n - 1) / 2, height);
		//cout << endl;
		return ans;
	}
};