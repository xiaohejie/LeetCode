#include<iostream>
#include<vector>
using namespace std;
/*
	剑指 Offer II 077. 链表排序
		使用归并排序 + vector
		使用归并排序 + 快慢结点
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
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}

	ListNode* sortList(ListNode* head, ListNode* tail) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode* slow = head, * fast = head;
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		ListNode* mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}

	ListNode* merge(ListNode* head1, ListNode* head2) {
		ListNode* dummyHead = new ListNode(0);
		ListNode* temp = dummyHead, * temp1 = head1, * temp2 = head2;
		while (temp1 != nullptr && temp2 != nullptr) {
			if (temp1->val <= temp2->val) {
				temp->next = temp1;
				temp1 = temp1->next;
			}
			else {
				temp->next = temp2;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		if (temp1 != nullptr) {
			temp->next = temp1;
		}
		else if (temp2 != nullptr) {
			temp->next = temp2;
		}
		return dummyHead->next;
	}
};






class Solution {
	void mergeArr(vector<int>& arr, int low, int mid, int high) {
		int* tempArr = new int[high - low + 1];
		int i = low, j = mid + 1, k = 0;
		while (i <= mid && j <= high) {
			if (arr[i] < arr[j]) {
				tempArr[k] = arr[i];
				i++;
			}
			else {
				tempArr[k] = arr[j];
				j++;
			}
			k++;
		}
		while (i <= mid) {
			tempArr[k] = arr[i];
			i++;
			k++;
		}
		while (j <= high) {
			tempArr[k] = arr[j];
			k++;
			j++;
		}
		i = low;
		for (int tempK = 0; ((tempK < k) && (i <= high)); tempK++) {
			arr[i] = tempArr[tempK];
			i++;
		}
		delete[] tempArr;
		tempArr = NULL;
	}
	void sortArr(vector<int>& arr, int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			sortArr(arr, low, mid);			//递归拆分左边的子序列
			sortArr(arr, mid + 1, high);	//递归拆分右边的子序列
			mergeArr(arr, low, mid, high);	//将两个有序的子序列合并成一个新的有序序列
		}
	}
public:
	ListNode* sortList(ListNode* head) {
		vector<int> vec;
		ListNode* node = head;
		while (!node)
		{
			vec.push_back(node->val);
			node = node->next;
		}
		int n = vec.size();
		sortArr(vec, 0, n - 1);
		ListNode* DummyNode = new ListNode(-1);
		DummyNode->next = node;
		node = new ListNode(vec[0]);
		for (int i = 1; i < n; i++) {
			ListNode* temp = new ListNode(vec[i]);
			node->next = temp;
			node = temp;
		}
		return DummyNode->next;
	}
};