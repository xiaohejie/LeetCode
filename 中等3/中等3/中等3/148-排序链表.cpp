#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	149-排序链表
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
	static bool cmp(ListNode* a, ListNode* b) {
		return a->val < b->val;
	}
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		vector<ListNode* > vec;
		ListNode* cur = head;
		while (cur)
		{
			vec.push_back(cur);
			cur = cur->next;
		}

		//对vec进行排序
		sort(vec.begin(), vec.end(), cmp);
		// for(auto& v : vec){
		//     cout << v->val << "-";
		// }
		ListNode* dummyNode = new ListNode(-1);
		vec[0]->next = nullptr;
		ListNode* newNode = vec[0];
		//cout << newNode->val << "-";
		dummyNode->next = newNode;
		//cout << dummyNode->next->val << " ";
		for (int i = 1; i < vec.size(); i++) {
			vec[i]->next = nullptr;
			newNode->next = vec[i];
			//cout << newNode->next->val << "-";
			newNode = vec[i];
		}
		// ListNode* curr = dummyNode->next;
		// while(curr){
		//     cout << curr->val << "-";
		//     curr = curr->next;
		// }
		return dummyNode->next;
	}
};