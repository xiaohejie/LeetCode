#include<iostream>
#include<vector>
using namespace std;
/*
	450. ɾ�������������еĽڵ�
*/
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
typedef struct {
	TreeNode* root;
}Tree;


class Solution1 {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->val > key) {
			root->left = deleteNode(root->left, key);
			return root;
		}
		if (root->val < key) {
			root->right = deleteNode(root->right, key);
			return root;
		}
		if (root->val == key) {
			//�ٽ����ж�
			if (root->left == nullptr && root->right == nullptr) {
				//ΪҶ�ӽ��
				return nullptr;
			}
			if (root->right == nullptr) {
				//�ҽڵ�Ϊ��
				return root->left;
			}
			if (root->left == nullptr) {
				//��ڵ�Ϊ��
				return root->right;
			}
			//���ҽڵ㶼����
			TreeNode* node = root->right;
			while (node->left) {
				//�ҵ�����������С�ڵ�
				node = node->left;
			}
			node->left = root->left;
			root = root->right;
		}
		return root;
	}
};

/*
	�÷�����˼·��
		������������ʹ���������
		�ҳ�key{
			û�еĻ�ֱ�ӷ���
		}
		����{
			ɾ��key��Ȼ�����¹������������������ǹ��������������������⣩
		}
*/
class Solution {
public:
	//�����������
	void helper(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		helper(root->left, vec);
		vec.push_back(root->val);
		helper(root->right, vec);
	}
	void insert(Tree* tree, int val) {
		//��val�����һ����
		TreeNode* node = (TreeNode*)malloc((sizeof(TreeNode)));
		node->val = val;
		node->left = NULL;
		node->right = NULL;

		if (tree->root == NULL) {
			tree->root = node;
		}
		else {
			TreeNode* temp = tree->root;
			while (temp != NULL) {
				if (val < temp->val) {
					//������
					if (temp->left == NULL) {
						temp->left = node;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else {
					//������
					if (temp->right == NULL) {
						temp->right = node;
						return;
					}
					else {
						temp = temp->right;
					}
				}
			}
		}
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		vector<int> vec;
		//�õ�����
		helper(root, vec);
		//ɾ��key
		bool isHas = 0;
		for (vector<int>::iterator it = vec.begin(); it != vec.end();) {
			if (*it == key) {
				isHas = 1;
				cout << *it << "  ";
				vec.erase(it);
				break;
			}
			it++;
		}
		if (isHas == 0) {
			return root;
		}
		//����Ļ����¹�������������
		Tree* tree = (Tree*)malloc(sizeof(Tree));
		tree->root = NULL;
		for (int i = 0; i < vec.size(); i++) {
			insert(tree, vec[i]);
		}
		return tree->root;
	}
};