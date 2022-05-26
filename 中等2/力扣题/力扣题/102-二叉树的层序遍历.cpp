#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
	�������Ĳ��������

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
	//ʹ�ö��У���ÿһ��Ľ��Ž�ȥ
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		//������ڵ�
		q.push(root);
		//�������л��н��
		while (!q.empty()) {
			int count = q.size();		//��¼��ǰ�������ж��ٸ���㣬Ҳ���Ǹò����ж��ٸ����
			vector<int> res;
			while (count) {
				TreeNode* node = q.front();		//ȡ��ͷ���
				q.pop();
				res.push_back(node->val);
				count--;
				//����������������ͷŽ�ȥ
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