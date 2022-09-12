#include<iostream>
using namespace std;
/*
	669. �޼�����������
		ʹ�õ���
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
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return nullptr;
		}
		//��ýڵ��ֵС��low��˵���ýڵ��Լ��ýڵ����������������Ҫ��
		if (root->val < low) {
			//���Ǿ���Ҫ�����ýڵ��������
			return trimBST(root->right, low, high);
		}
		else if (root->val > high) {
			//����ýڵ��ֵ����high��˵���ýڵ��Լ��ýڵ������������Ҫ�޼�
			//���ظýڵ��������
			return trimBST(root->left, low, high);
		}
		else {
			//˵���ýڵ���[low, high]�ķ�Χ��
			//�ýڵ㱣������������������������������
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}
	}
};