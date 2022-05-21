#include<iostream>
#include<vector>
using namespace std;
/*
	·���ܺ�II��
		������ȱ��� + ����
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
	vector<vector<int>> res;
	vector<int> vec;
	/*����˼·������һ��*/
	void backTrack(TreeNode* root, int targetSum) {
		//��ֹ���������ʵ��սڵ��˳���
		if (root == nullptr) {
			return;
		}

		//��root->val�ӽ�ȥ�����ж�
		vec.push_back(root->val);
		targetSum -= root->val;
		if (targetSum == 0 && root->left == nullptr && root->right == nullptr) {
			res.push_back(vec);
			//return;       ����Ϊʲô����Ҫreturn������㲻����
		}

		backTrack(root->left, targetSum);
		backTrack(root->right, targetSum);
		vec.pop_back();

	}
	void backTrack1(TreeNode* root, int targetSum) {
		//����ǰ������vec��������targetSum
		vec.push_back(root->val);
		targetSum -= root->val;

		//�����ж�
		if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
			res.push_back(vec);
		}
		if (root->left) {
			backTrack1(root->left, targetSum);
		}
		if (root->right) {
			backTrack1(root->right, targetSum);
		}
		vec.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return res;
		}
		backTrack1(root, targetSum);
		return res;
	}
};