#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	508-���ִ�����������Ԫ�غ�
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
	unordered_map<int, int> ans;
	int maxCount = 0;
public:
	//����������ȱ���
	int dfs(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		//����������
		int sum = root->val + dfs(root->left) + dfs(root->right);
		//���������ͳ���������
		maxCount = max(maxCount, ++ans[sum]);
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		dfs(root);
		vector<int> res;
		for (auto& [s, i] : ans) {
			if (i == maxCount) {
				res.push_back(s);
			}
		}
		return res;
	}
};