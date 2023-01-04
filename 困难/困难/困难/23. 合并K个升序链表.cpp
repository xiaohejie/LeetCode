#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	23. 合并K个升序链表
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> vec;
		ListNode* dummyNode = new ListNode(-1);
		ListNode* ans = nullptr;
		for (auto& list : lists) {
			while (list != nullptr)
			{
				vec.push_back(list->val);
				list = list->next;
			}
		}
		sort(vec.begin(), vec.end());
		ans = new ListNode(vec[0]);
		dummyNode->next = ans;
		for (int i = 1; i < vec.size(); i++) {
			ListNode* node = new ListNode(vec[i]);
			ans->next = node;
			ans = ans->next;
		}
		return dummyNode->next;
	}
};