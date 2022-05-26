#include<iostream>
#include<vector>
using namespace std;
/*
	
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
	vector<int> nums;
	//ʹ���������
	void inorder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left);
		nums.push_back(root->val);
		inorder(root->right);
	}
	//����������û�а�˳�����е�����
	vector<int> findNum(vector<int>& nums) {
		vector<int> ans;
		int index1 = -1, index2 = -1;
		//�ҵ������������(���������Ҫע��һ��)
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[i-1]) {
				index2 = i;
				if (index1 == -1) {
					index1 = i-1;
				}
				else {
					break;
				}
			}
		}
		ans.push_back(nums[index1]);
		ans.push_back(nums[index2]);
		return ans;
	}
	//�ڶ����������н�����������
	void recover(TreeNode* root, int total, int a, int b) {
		if (root != nullptr) {
			if (root->val == a || root->val == b) {
				root->val = (root->val == a ? b : a);
				total--;
				if (total == 0) {
					return;
				}
			}
			recover(root->left, total, a, b);
			recover(root->right, total, a, b);
		}
	}
	void recoverTree(TreeNode* root) {
		inorder(root);		//�õ��д�С������
		//�ҳ�������û�а�˳�����е�����
		vector<int> ans = findNum(nums);
		int a = ans[0], b = ans[1];
		//�ڶ����������н�����������
		recover(root, 2, a, b);
	}
};