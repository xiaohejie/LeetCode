#include<iostream>
#include<vector>
using namespace std;
/*
	分隔链表：
	方法1：（但没做出来，有问题）
		找出第一个大于target的数的前一个位置
		然后遍历该链表，将小于target的数依次进行尾插
	方法2：
		直接用两个链表：
			将大于等于target的放到一起
			小于target的放一起
			最后在进行合并
			
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
class Solution {
public:
	//找出链表中第一个大于target的前一个位置
	ListNode* helper(ListNode* head, int x) {
		ListNode* indexNode = NULL;		//目标结点
		ListNode* dummyHead = new ListNode(0);		//哨兵节点
		ListNode* cur = head;
		dummyHead->next = cur;
		ListNode* prev = dummyHead;
		while (cur) {
			if (cur->val < x) {
				prev = cur;
				cur = cur->next;
			}
			else {
				//找到目标结点
				indexNode = prev;
				break;
			}
		}
		return indexNode;
	}
	ListNode* partition(ListNode* head, int x) {
		//找到目标结点
		ListNode* indexNode = helper(head, x);
		ListNode* cur = head;
		ListNode* dummyHead = new ListNode(0);		//哨兵节点
		ListNode* cur = head;
		dummyHead->next = cur;
		ListNode* prev = dummyHead;
		while (cur) {
			if (cur->val < x) {
				prev->next = cur->next;
				cur->next = indexNode->next;
				indexNode->next = cur;
			}
			else {
				prev = cur;
				cur = cur->next;
			}
		}
		return dummyHead->next;
	}
};
*/

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* lowerNode = new ListNode(0);
		ListNode* dummyNode1 = lowerNode;
		ListNode* upperNode = new ListNode(0);
		ListNode* dummyNode2 = upperNode;
		ListNode* cur = head;
		while(cur) {
			if (cur->val < x) {
				lowerNode->next = cur;
				lowerNode = lowerNode->next;
				cur = cur->next;
			}
			else {
				upperNode->next = cur;
				upperNode = upperNode->next;
				cur = cur->next;
			}
		}
		//在进行合并
		upperNode->next = nullptr;      //（这里要进行置空**很重要**）
		lowerNode->next = dummyNode2->next;
		return dummyNode1->next;
	}
};