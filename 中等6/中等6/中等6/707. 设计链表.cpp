#include<iostream>
using namespace std;
/*
	707. 设计链表
        //使用单向链表和双向链表
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val) :val(_val), next(nullptr) {}
};
class MyLinkedList {
private:
    int size;
    ListNode* head;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode* cur = head;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        index = max(0, index);
        size++;
        ListNode* pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode* toAdd = new ListNode(val);
        toAdd->next = pred->next;
        pred->next = toAdd;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        size--;
        ListNode* pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode* p = pred->next;
        pred->next = pred->next->next;
        delete p;
    }
};