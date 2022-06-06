#include<iostream>
#include<vector>
using namespace std;
/*
	450. 删除二叉搜索树中的节点
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
			//再进行判断
			if (root->left == nullptr && root->right == nullptr) {
				//为叶子结点
				return nullptr;
			}
			if (root->right == nullptr) {
				//右节点为空
				return root->left;
			}
			if (root->left == nullptr) {
				//左节点为空
				return root->right;
			}
			//左右节点都存在
			TreeNode* node = root->right;
			while (node->left) {
				//找到右子树的最小节点
				node = node->left;
			}
			node->left = root->left;
			root = root->right;
		}
		return root;
	}
};

/*
	该方法的思路：
		将二插搜索树使用中序遍历
		找出key{
			没有的话直接返回
		}
		否则{
			删除key，然后重新构建搜索二叉树（但是构建二插搜索树这有问题）
		}
*/
class Solution {
public:
	//进行中序遍历
	void helper(TreeNode* root, vector<int>& vec) {
		if (root == nullptr) {
			return;
		}
		helper(root->left, vec);
		vec.push_back(root->val);
		helper(root->right, vec);
	}
	void insert(Tree* tree, int val) {
		//将val打包成一棵树
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
					//向左移
					if (temp->left == NULL) {
						temp->left = node;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else {
					//向右移
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
		//得到数组
		helper(root, vec);
		//删除key
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
		//否则的话重新构成搜索二叉树
		Tree* tree = (Tree*)malloc(sizeof(Tree));
		tree->root = NULL;
		for (int i = 0; i < vec.size(); i++) {
			insert(tree, vec[i]);
		}
		return tree->root;
	}
};