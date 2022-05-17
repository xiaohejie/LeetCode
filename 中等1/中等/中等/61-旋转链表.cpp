#include<iostream>
using namespace std;
/*
	旋转链表：
		设置两个新链表。将完整链表从第k个数断开，然后重新连接。
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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* curr = head;
		int len = 0;
		//计算链表长度
		while (curr) {
			curr = curr->next;
			len++;
		}
		//特殊情况
		if (len == 0 || k == 0 || len == 1) {
			return head;
		}
		int add = len - k % len;		//(这一步挺重要)
		if (add == len) {
			//如果移动的长度等于链表长度，就直接返回
			return head;
		}
		ListNode* firstNode = head;
		while(add > 1){
			head = head->next;
			add--;
		}
		ListNode* secondNode = head->next;
		head->next = nullptr;
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = secondNode;
		while (secondNode->next) {
			secondNode = secondNode->next;
		}
		secondNode->next = firstNode;
		return dummyNode->next;
		/*
		ListNode* firstNode = head;
		ListNode* curr = head;
		int len = 0;
		while (curr) {
			curr = curr->next;
			len++;
		}
		if (len == 0 || k == 0 || len == 1) {
			return head;
		}
		k = k % len;
		k = len - k;
		while (k >0) {
			head = head->next;
			k--;
		}
		ListNode* secondNode = head->next;
		head->next = nullptr;
		//编程两段链表之后，再重新拼接
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = secondNode;
		while (secondNode->next) {
			secondNode = secondNode->next;
		}
		secondNode->next = firstNode;
		return dummyNode->next;*/
	}
};