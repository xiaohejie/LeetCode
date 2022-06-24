#include<iostream>
#include<vector>
using namespace std;
/*
	109-有序链表转化为二插搜索树
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
	//利用快慢指针查找链表的中间节点
	ListNode* findMid(ListNode* head) {
		//需要记录中间节点的前一个指针
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