#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
/*
	199. ������������ͼ
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
	vector<int> rightSideView(TreeNode* root) {
		//��¼���ұ߽ڵ����Ⱥ�ֵ
		unordered_map<int, int> rightmostValueAtDepth;
		int max_depth = -1;		//���ڼ�¼������

		stack<TreeNode*> nodeStack;		//��ͬһ��ȵĽ�����ջ��
		stack<int> depthStack;			//��ջ���ڼ�¼�ڵ�����
		nodeStack.push(root);			//ͷ��㼰�����
		depthStack.push(0);

		while (!nodeStack.empty()) {
			//��ջ��ȡ���ڵ㼰�����
			TreeNode* node = nodeStack.top();
			nodeStack.pop();
			int depth = depthStack.top();
			depthStack.pop();

			//�����������Լ�map���������ұ߽�㣩
			if (node != nullptr) {
				//ά����������������
				max_depth = max(max_depth, depth);

				//��������ڶ�Ӧ��ȵĽ�����ǲŲ���
				if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()) {
					rightmostValueAtDepth[depth] = node->val;
				}
				//����һ��Ľ���ֵ����ջ��
				nodeStack.push(node->left);
				nodeStack.push(node->right);
				depthStack.push(depth + 1);
				depthStack.push(depth + 1);
			}
		}
		//ȥ�����ұ߽ڵ��ֵ
		vector<int> rightView;
		for (int depth = 0; depth <= max_depth; depth++) {
			rightView.push_back(rightmostValueAtDepth[depth]);
		}
		return rightView;
	}
};