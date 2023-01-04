#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
/*
	199. 二叉树的右视图
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
	vector<int> rightSideView(TreeNode* root) {
		//记录最右边节点的深度和值
		unordered_map<int, int> rightmostValueAtDepth;
		int max_depth = -1;		//用于记录最大深度

		stack<TreeNode*> nodeStack;		//将同一深度的结点放入栈中
		stack<int> depthStack;			//该栈用于记录节点的深度
		nodeStack.push(root);			//头结点及其深度
		depthStack.push(0);

		while (!nodeStack.empty()) {
			//从栈中取出节点及其深度
			TreeNode* node = nodeStack.top();
			nodeStack.pop();
			int depth = depthStack.top();
			depthStack.pop();

			//更新最大深度以及map容器（最右边结点）
			if (node != nullptr) {
				//维护二叉树的最大深度
				max_depth = max(max_depth, depth);

				//如果不存在对应深度的结点我们才插入
				if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()) {
					rightmostValueAtDepth[depth] = node->val;
				}
				//将下一层的结点和值存入栈中
				nodeStack.push(node->left);
				nodeStack.push(node->right);
				depthStack.push(depth + 1);
				depthStack.push(depth + 1);
			}
		}
		//去除最右边节点的值
		vector<int> rightView;
		for (int depth = 0; depth <= max_depth; depth++) {
			rightView.push_back(rightmostValueAtDepth[depth]);
		}
		return rightView;
	}
};