#include<iostream>
using namespace std;
/*
	143. ��������
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* helper(ListNode* head) {
		ListNode* newHead = nullptr;
		ListNode* cur = head;
		while (cur) {
			ListNode* next = cur->next;
			cur->next = newHead;
			newHead = cur;
			cur = next;
		}
		return newHead;
	}
	void reorderList(ListNode* head) {
		//1��ͨ�������������м�ڵ�
		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* pre = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			pre = slow;
			slow = slow->next;
		}
		//2�����ս������Ľ���������
		pre->next = nullptr;
		ListNode* newHead = helper(slow);
		//3�������ཻ����
		ListNode* preNode = head;
		ListNode* temp = head;
		while (newHead && preNode) {
			ListNode* n1 = preNode->next;
			ListNode* n2 = newHead->next;
			preNode->next = newHead;
			newHead->next = n1;
			temp = newHead;
			preNode = n1;
			newHead = n2;
		}
		if (newHead) {
			temp->next = newHead;
		}
	}
};
