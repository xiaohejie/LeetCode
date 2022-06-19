#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
/*
	103-�������ľ���β������
		�ڲ�������Ļ����ϣ��Զ���������ż�Խ����ж�
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
		}

		//���������װ�ڵ�
		queue<TreeNode* > q;
		q.push(root);

		while (!q.empty())
		{
			//����װ�ò�Ľڵ�ֵ
			vector<int> res;
			int count = q.size();
			while (count--)
			{
				TreeNode* cur = q.front();	//��ͷ
				res.push_back(cur->val);		//�Ѷ�ͷ�Ž�res��
				//�ж϶�ͷ��û�������ӽڵ�
				if (cur->left) {
					q.push(cur->left);
				}
				if (cur->right) {
					q.push(cur->right);
				}
				q.pop();		//ɾ����ͷ
			}
			//�ò��������
			//�жϸò��������㻹��ż����
			if (ans.size() & 1) { reverse(res.begin(), res.end()); }
			ans.push_back(res);
		}
	}
};