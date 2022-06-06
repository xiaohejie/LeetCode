#include<iostream>
#include<vector>
using namespace std;
/*
	根节点到叶节点数字之和
		使用dfs
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
     void helper(TreeNode* root, vector<int>& vec, int sum) {
 		sum = sum * 10 + root->val;
		if (!root->left && !root->right) {
			vec.push_back(sum);
		}
		if (root->left) {
			helper(root->left, vec, sum);
		}
		if (root->right) {
			helper(root->right, vec, sum);
		}
 	}
 	int sumNumbers(TreeNode* root) {
 		vector<int> vec;
 		helper(root, vec, 0);
 		int ans = 0; 
 		for (auto& v:vec) {
             cout << v << " "; 
 			ans += v;
 		}
 		return ans;
 	}





	/*
	int ans = 0;
public:
	void dfs(TreeNode* root, int num) {
		if (root == nullptr) {
			return ;
		}
		num = num * 10 + root->val;
		if (!root->left && !root->right) {
			//到达叶子结点，ans加上
			ans += num;
		}
		if (root->left) {
			dfs(root->left, num);
		}
		if (root->right) {
			dfs(root->right, num);
		}
	}
	int sumNumbers(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
	*/
};