#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>


/*
	106-������ͺ���������й����������
		�����ڴ�ǰ����������������û���
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
	unordered_map<int, int> map;
	int len;
public:
	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pol, int por) {
		if (il > ir || pol > por) {
			return nullptr;
		}
		//��¼��postorder[pol]Ϊ���ڵ���������ж��ٸ����
		int k = map[postorder[por]] - il;
		//����������
		TreeNode* root = new TreeNode(postorder[por]);
		root->left = build(inorder, postorder, il, il + k - 1, pol, pol + k - 1);
		root->right = build(inorder, postorder, il + k + 1, ir, pol + k, por - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		len = inorder.size();
		for (int i = 0; i < len; i++) {
			map[inorder[i]] = i;
		}
		//����������
		return build(inorder, postorder, 0, len - 1, 0, len - 1);
	}
};