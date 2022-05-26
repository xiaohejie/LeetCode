#include<iostream>
#include<queue>
#include<vector>
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
	//使用队列，将每一层的结点放进去
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		//放入根节点
		q.push(root);
		//当队列中还有结点
		while (!q.empty()) {
			int count = q.size();		//记录当前队列中有多少个结点，也就是该层中有多少个结点
			vector<int> res;
			while (count) {
				TreeNode* node = q.front();		//取出头结点
				q.pop();
				res.push_back(node->val);
				count--;
				//如果有左右子树，就放进去
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			ans.push_back(res);
		}
		return ans;
	}
};