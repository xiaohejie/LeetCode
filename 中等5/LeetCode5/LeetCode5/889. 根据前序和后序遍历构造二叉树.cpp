#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	889. ����ǰ��ͺ���������������
		ǰ�򣺸�����������������
		������������������������
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
	unordered_map<int, int> premap;
	unordered_map<int, int> postmap;
	TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int pres, int pree, int posts, int poste) {
		if (pres > pree || posts > poste) {
			return nullptr;
		}
		TreeNode* node = new TreeNode(preorder[pres]);
		int lidx = postmap[preorder[pres]] - 1;		//�õ��˺��������е��±�
		int lvalue = postorder[lidx];				//�õ�ֵ
		int ridx = premap[preorder[pres]] + 1;
		int rvalue = preorder[ridx];
		node->left = helper(preorder, postorder, pres + 1, premap[lvalue] - 1, posts, postmap[rvalue]);
		node->right = helper(preorder, postorder, premap[lvalue], pree, postmap[rvalue], poste - 1);
	}
public:
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		int len = preorder.size();
		for (int i = 0; i < len; i++) {
			premap[preorder[i]] = i;
		}
		for (int i = 0; i < len; i++) {
			postmap[postorder[i]] = i;
		}
		return helper(preorder, postorder, 0, len - 1, 0, len - 1);
	}
};