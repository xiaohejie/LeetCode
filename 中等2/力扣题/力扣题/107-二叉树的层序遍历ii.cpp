#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
	//ʹ�ö��У���ͷ������Ȼ���ڵ���
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(root);		//��ͷ���Ž�ȥ
		while (!q.empty()) {
			int count = q.size();
			vector<int> vec;
			while (count--) {
				TreeNode* node = q.front();
				q.pop();
				vec.push_back(node->val);
				//�����������Ž�ȥ
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			//���ò�Ľ��Ž�ȥ
			ans.push_back(vec);
		}
		//ȫ���Ž�ȥ֮����е���
		reverse(ans.begin(), ans.end());
		return ans;
	}
};