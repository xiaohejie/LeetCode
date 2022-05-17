#include<iostream>
using namespace std;
/*
	��ת����
		������������������������ӵ�k�����Ͽ���Ȼ���������ӡ�
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
		//����������
		while (curr) {
			curr = curr->next;
			len++;
		}
		//�������
		if (len == 0 || k == 0 || len == 1) {
			return head;
		}
		int add = len - k % len;		//(��һ��ͦ��Ҫ)
		if (add == len) {
			//����ƶ��ĳ��ȵ��������ȣ���ֱ�ӷ���
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
		//�����������֮��������ƴ��
		ListNode* dummyNode = new ListNode(-1);
		dummyNode->next = secondNode;
		while (secondNode->next) {
			secondNode = secondNode->next;
		}
		secondNode->next = firstNode;
		return dummyNode->next;*/
	}
};