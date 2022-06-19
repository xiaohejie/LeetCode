#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
	103-二叉树的锯齿形层序遍历
		在层序遍历的基础上，对二叉树的奇偶性进行判断
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}

		//定义队列来装节点
		queue<TreeNode* > q;
		q.push(root);

		while (!q.empty())
		{
			//用来装该层的节点值
			vector<int> res;
			int count = q.size();
			while (count--)
			{
				TreeNode* cur = q.front();	//对头
				res.push_back(cur->val);		//把对头放进res中
				//判断对头有没有左右子节点
				if (cur->left) {
					q.push(cur->left);
				}
				if (cur->right) {
					q.push(cur->right);
				}
				q.pop();		//删除对头
			}
			//该层遍历结束
			//判断该层是奇数层还是偶数层
			if (ans.size() & 1) { reverse(res.begin(), res.end()); }
			ans.push_back(res);
		}
	}
};