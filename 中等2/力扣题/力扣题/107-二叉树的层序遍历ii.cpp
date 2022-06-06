#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
	二叉树的层序遍历：
		
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
	//使用队列，从头遍历，然后在倒置
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);		//将头结点放进去
		while (!q.empty()) {
			int count = q.size();
			vector<int> vec;
			while (count--) {
				TreeNode* node = q.front();
				q.pop();
				vec.push_back(node->val);
				//将左右子树放进去
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			//将该层的结点放进去
			ans.push_back(vec);
		}
		//全部放进去之后进行倒置
		reverse(ans.begin(), ans.end());
		return ans;
	}
};