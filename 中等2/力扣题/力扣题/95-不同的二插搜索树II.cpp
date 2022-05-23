#include<iostream>
#include<vector>
using namespace std;
/*
	��ͬ�Ķ���������II��

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
	vector<TreeNode*> generateTrees(int n) {
		return helper(1, n);
	}
	vector<TreeNode*> helper(int left, int right) {
		if (left > right) {
			return { nullptr };
		}
		vector<TreeNode*> ans;
		//ö�����п��еĸ��ڵ�
		for (int i = left; i <= right; i++) {			
			vector<TreeNode*> lNode = helper(left, i-1);	//������
			vector<TreeNode*> rNode = helper(i+1, right);	//������
			//�ֱ������������������������ڵ���ϳ��µ���
			for (int m = 0; m < lNode.size(); m++) {
				for (int n = 0; n < rNode.size(); n++) {
					TreeNode* node = new TreeNode(i);		//���ڵ�
					node->left = lNode[m];
					node->right = rNode[n];
					ans.push_back(node);
				}
			}
		}
		return ans;
	}	
};