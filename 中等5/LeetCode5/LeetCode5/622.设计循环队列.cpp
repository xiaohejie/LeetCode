#include<iostream>
using namespace std;
/*
	622. 设计循环队列
        使用链表或者数组
        链表简单，数组比较麻烦
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val; next = nullptr;
    };
};
class MyCircularQueue {
    ListNode* head;
    ListNode* tail;
    int capicity;
    int size;
public:
    MyCircularQueue(int k) {
        this->capicity = k;
        this->size = 0;
        this->head = this->tail = nullptr;
    }

    bool enQueue(int value) {
        if (isFull) {
            return false;
        }
        ListNode* node = new ListNode(value);
        if (!head) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty) {
            return false;
        }
        ListNode* node = head;
        head = head->next;
        size--;
        delete node;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        return size == capicity;
    }
};