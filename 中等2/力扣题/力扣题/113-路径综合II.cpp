#include<iostream>
#include<vector>
using namespace std;
/*
	路径总和II：
		深度优先遍历 + 回溯
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
	vector<vector<int>> res;
	vector<int> vec;
	/*两种思路，都看一下*/
	void backTrack(TreeNode* root, int targetSum) {
		//中止条件（访问到空节点退出）
		if (root == nullptr) {
			return;
		}

		//把root->val加进去进行判断
		vec.push_back(root->val);
		targetSum -= root->val;
		if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
			res.push_back(vec);
			//return;       这里为什么不需要return（这里搞不懂）
		}

		backTrack(root->left, targetSum);
		backTrack(root->right, targetSum);
		vec.pop_back();

	}
	void backTrack1(TreeNode* root, int targetSum) {
		//将当前结点加入vec，并更新targetSum
		vec.push_back(root->val);
		targetSum -= root->val;

		//进行判断
		if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
			res.push_back(vec);
		}
		if (root->left) {
			backTrack1(root->left, targetSum);
		}
		if (root->right) {
			backTrack1(root->right, targetSum);
		}
		vec.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return res;
		}
		backTrack1(root, targetSum);
		return res;
	}
};