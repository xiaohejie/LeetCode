#include<iostream>
#include<stack>
using namespace std;
/*
	�����е�������ӣ�
		
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
	//��������ĳ���
	int lenHelper(ListNode* l) {
		ListNode* cur = l;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		return count;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = lenHelper(l1);
		int len2 = lenHelper(l2);
		int len = abs(len1 - len2);
		ListNode* l = new ListNode(0);		//�������
		if (len1 > len2) {
			//l1��
			l = l1;
			while(len>0){
				l1 = l1->next;
				len--;
			}
			while (l1 != nullptr) {
				l1->val += l2->val;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		else {
			//L2��
			l = l2;
			while (len>0) {
				l2 = l2->next;
				len--;
			}
			while (l2 != nullptr)
			{	
				l2->val += l1->val;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		stack<int> s;
		while (l) {
			s.push(l->val);
			l = l->next;
		}
		int flag = 0;
		ListNode* ans = nullptr;
		while (s.empty())
		{
			int num = s.top();

			int n = (num + flag) % 10;
			flag = (num + flag) / 10;

			ListNode* res = new ListNode(n);
			res->next = ans;
			ans = res;
			s.pop();
		}
		if (flag == 1) {
			ListNode* res = new ListNode(1);
			res->next = ans;
			ans = res;
		}
		return ans;
	}
};