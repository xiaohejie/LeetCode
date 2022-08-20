#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	654. ×î´ó¶þ²æÊ÷
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
	int maxNum(vector<int>& nums, int left, int right) {
		int index = left;
		for (int i = left + 1; i <= right; i++) {
			if (nums[index] < nums[i]) {
				index = i;
			}
		}
		return index;
	}
	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (nums.size() == 0) {
			return nullptr;
		}
		int index = maxNum(nums, left, right);
		TreeNode* node = new TreeNode(nums[index]);
		node->left = helper(nums, left, index - 1);
		node->right = helper(nums, index +1, right);
		return node;
	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};