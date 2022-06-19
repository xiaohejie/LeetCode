#include<iostream>
#include<vector>
using namespace std;
/*
	������չ��Ϊ����ʹ�ÿռ临�Ӷ�ΪO(1)����
		
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
	void flatten(TreeNode* root) {
		TreeNode* node = root;
		//����ڵ������������
		while (node){
			if(node->left) {
				//�ҵ������������ҽڵ�
				TreeNode* newNode = node->left;
				while (newNode->right) {
					newNode = newNode->right;
				}
				//�������������ҽڵ����ϵ�ǰ�ڵ���ҽڵ�
				newNode->right = node->right;
				node->right = node->left;
				node->left = nullptr;
			}
			node = node->right;
		}
	}
};