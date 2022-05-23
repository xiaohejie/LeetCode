#include<iostream>
#include<vector>
using namespace std;
/*
	不同的二插搜索树II：

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
	vector<TreeNode*> generateTrees(int n) {
		return helper(1, n);
	}
	vector<TreeNode*> helper(int left, int right) {
		if (left > right) {
			return { nullptr };
		}
		vector<TreeNode*> ans;
		//枚举所有可行的根节点
		for (int i = left; i <= right; i++) {			
			vector<TreeNode*> lNode = helper(left, i-1);	//左子树
			vector<TreeNode*> rNode = helper(i+1, right);	//右子树
			//分别遍历左子树和右子树，与根节点组合成新的树
			for (int m = 0; m < lNode.size(); m++) {
				for (int n = 0; n < rNode.size(); n++) {
					TreeNode* node = new TreeNode(i);		//根节点
					node->left = lNode[m];
					node->right = rNode[n];
					ans.push_back(node);
				}
			}
		}
		return ans;
	}	
};