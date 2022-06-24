#include<iostream>
#include<vector>
using namespace std;
/*
	109-��������ת��Ϊ����������
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
	//���ÿ���ָ�����������м�ڵ�
	ListNode* findMid(ListNode* head) {
		//��Ҫ��¼�м�ڵ��ǰһ��ָ��
		ListNode* pre = nullptr;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if(pre) pre->next = nullptr;
		return slow;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		if (head->next = nullptr) {
			return new TreeNode(head->val);
		}
		ListNode* midHead = findMid(head);
		TreeNode* root = new TreeNode(midHead->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(midHead->next);
		return root;
	}
};