#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	1302. 层数最深叶子节点的和
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
	int ans;
	int maxDepth = 0;
	unordered_map<int, vector<int>> map;
	void dfs(TreeNode* root, int depth) {
		if (root->left == nullptr && root->right == nullptr) {
			//cout << maxDepth << "-" << depth << "-" << ans << endl;
			if (maxDepth < depth) {
				maxDepth = depth;
				ans = root->val;
			}
			else if (maxDepth == depth) {
				ans += root->val;
			}
			return;
		}
		if (root->left) {
			dfs(root->left, depth + 1);
		}
		if (root->right) {
			dfs(root->right, depth + 1);
		}
	}
public:
	int deepestLeavesSum(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
};