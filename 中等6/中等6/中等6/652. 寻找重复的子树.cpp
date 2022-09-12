#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
/*
	652. Ѱ���ظ�������
		ʹ�����л������л�һ�ö������ο���ָoffer37 ���л���������
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
	unordered_map<string, int> map;
	vector<TreeNode*> ans;
public:
	string dfs(TreeNode* root) {
		if (root == nullptr) {
			return "";
		}
		string ss = to_string(root->val) + "(" + dfs(root->left) + ")" + "(" + dfs(root->right) + ")";
		map[ss]++;
		if (map[ss] == 2) {
			ans.push_back(root);
		}
		return ss;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return ans;
	}
};