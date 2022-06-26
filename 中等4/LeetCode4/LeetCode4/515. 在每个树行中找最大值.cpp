#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	515. 在每个树行中找最大值
		广度优先遍历
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		if (root == nullptr) {
			return ans;
		}
		queue<TreeNode* > q;
		q.push(root);
		while (!q.empty()) {
			int count = q.size();
			int maxValue = INT_MIN;
			while (count--) {
				maxValue = max(maxValue, q.front()->val);
				if (q.front()->left) {
					q.push(q.front()->left);
				}
				if (q.front()->right) {
					q.push(q.front()->right);
				}
				q.pop();
			}	
			ans.push_back(maxValue);
		}
		return ans;
	}
};