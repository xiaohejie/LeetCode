#include<iostream>
#include<stack>
using namespace std;
/*
	173. 二叉搜索树迭代器
		使用单调栈或者使用队列
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class BSTIterator {
	TreeNode* cur;
	stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
		cur = root;
    }

    int next() {
		while (cur) {
			stk.push(cur);
			cur = cur->left;
		}
		cur = stk.top();
		stk.pop();
		int ret = cur->val;
		cur = cur->right;
		return ret;
    }

    bool hasNext() {
		return cur != nullptr || !stk.empty();
    }
};