#include<iostream>
using namespace std;
/*
	998. �������� II
		Ҫô�Ǹ��ڵ�Ҫô������������
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
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		TreeNode* node = new TreeNode(val);
		TreeNode* parent = nullptr;
		TreeNode* cur = root;
		while (cur) {
			if (cur->val < val) {
				if (!parent) {
					//������ڵ�Ϊ�գ���ʾcurΪ���ڵ�
					return new TreeNode(val, root, nullptr);
				}
				//����Ļ����������Ǹ��ڵ�
				//cur��node����������parent����������node
				parent->right = node;
				node->left = cur;
				return root;
			}
			else {
				//cur��ֵ����val
				//��������
				parent = cur;
				cur = cur->right;
			}
		}
		//��������û�з��صĻ������õ�ǰparent���ҽڵ�ָ��node
		parent->right = node;
		return root;
	}
};