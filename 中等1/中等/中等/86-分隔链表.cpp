#include<iostream>
#include<vector>
using namespace std;
/*
	�ָ�����
	����1������û�������������⣩
		�ҳ���һ������target������ǰһ��λ��
		Ȼ�������������С��target�������ν���β��
	����2��
		ֱ������������
			�����ڵ���target�ķŵ�һ��
			С��target�ķ�һ��
			����ڽ��кϲ�
			
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
	//�ҳ������е�һ������target��ǰһ��λ��
	ListNode* helper(ListNode* head, int x) {
		ListNode* indexNode = NULL;		//Ŀ����
		ListNode* dummyHead = new ListNode(0);		//�ڱ��ڵ�
		ListNode* cur = head;
		dummyHead->next = cur;
		ListNode* prev = dummyHead;
		while (cur) {
			if (cur->val < x) {
				prev = cur;
				cur = cur->next;
			}
			else {
				//�ҵ�Ŀ����
				indexNode = prev;
				break;
			}
		}
		return indexNode;
	}
	ListNode* partition(ListNode* head, int x) {
		//�ҵ�Ŀ����
		ListNode* indexNode = helper(head, x);
		ListNode* cur = head;
		ListNode* dummyHead = new ListNode(0);		//�ڱ��ڵ�
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
		//�ڽ��кϲ�
		upperNode->next = nullptr;      //������Ҫ�����ÿ�**����Ҫ**��
		lowerNode->next = dummyNode2->next;
		return dummyNode1->next;
	}
};