#include<iostream>
#include<vector>
using namespace std;
/*
	662. �����������
		ʹ�ù����������
		ͨ���ӱ�ǩ
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
	int widthOfBinaryTree(TreeNode* root) {
		unsigned long long res = 1;
		vector<pair<TreeNode*, unsigned long long>> arr;		//������¼ÿ���ڵ�ĵı�ǩ
		//�Ը��ڵ���г�ʼ��
		arr.push_back({root, 1});
		while (!arr.empty()) {
			//��������Ԫ�ز�Ϊ��
			vector<pair<TreeNode*, unsigned long long>> tmp;
			for (auto& [node, index] : arr) {
				if (node->left) {
					tmp.push_back({ node->left, index * 2 });
				}
				if (node->right) {
					tmp.push_back({ node->right, index * 2  + 1});
				}
			}
			res = max(res, arr.back().second - arr[0].second + 1);
			arr = move(tmp);
		}
		return res;
	}
};