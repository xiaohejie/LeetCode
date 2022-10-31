#include<iostream>
#include<vector>
using namespace std;
/*
	817. Á´±í×é¼þ
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
	int numComponents(ListNode* head, vector<int>& nums) {
		int count = 0;
		ListNode* node = head;
		while (node && node->next) {
			int num = node->val;
			int nextNum = node->next->val;
			if ((find(nums.begin(), nums.end(), num) != nums.end()) && (find(nums.begin(), nums.end(), nextNum) == nums.end())) {
				count++;
			}
			node = node->next;
		}
		if (find(nums.begin(), nums.end(), node->val) != nums.end()) {
			count += 1;
		}
		return count;
	}
};