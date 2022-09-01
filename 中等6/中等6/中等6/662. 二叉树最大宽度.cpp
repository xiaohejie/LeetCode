#include<iostream>
#include<vector>
using namespace std;
/*
	662. 二叉树最大宽度
		使用广度优先搜索
		通过加标签
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
	int widthOfBinaryTree(TreeNode* root) {
		unsigned long long res = 1;
		vector<pair<TreeNode*, unsigned long long>> arr;		//用来记录每个节点的的标签
		//对根节点进行初始化
		arr.push_back({root, 1});
		while (!arr.empty()) {
			//当数组中元素不为空
			vector<pair<TreeNode*, unsigned long long>> tmp;
			for (auto& [node, index] : arr) {
				if (node->left) {
					tmp.push_back({ node->left, index * 2 });
				}
				if (node->right) {
					tmp.push_back({ node->right, index * 2  + 1});
				}
			}
			res = max(res, arr.back().second - arr[0].second + 1);
			arr = move(tmp);
		}
		return res;
	}
};