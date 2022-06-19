#include<iostream>
#include<vector>
using namespace std;
/*
	二叉树展开为链表（使用空间复杂度为O(1)）：
		
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
		//如果节点的左子树存在
		while (node){
			if(node->left) {
				//找到左子树的最右节点
				TreeNode* newNode = node->left;
				while (newNode->right) {
					newNode = newNode->right;
				}
				//将左子树的最右节点连上当前节点的右节点
				newNode->right = node->right;
				node->right = node->left;
				node->left = nullptr;
			}
			node = node->right;
		}
	}
};