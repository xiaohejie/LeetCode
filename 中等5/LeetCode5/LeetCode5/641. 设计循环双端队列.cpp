#include<iostream>
using namespace std;
/*
	641. ���ѭ��˫�˶���
        ʹ������
*/
struct DlinkListNode {
    int val;
    DlinkListNode* prev, *next;
    DlinkListNode(int _val) :val(_val), prev(nullptr), next(nullptr) {}
};
class MyCircularDeque {
    DlinkListNode* head, * tail;
    int capacity;
    int size;
public:
    MyCircularDeque(int k): head(nullptr), tail(nullptr), capacity(k), size(0) {

    }

    bool insertFront(int value) {
        if (size == capacity) {
            //������Ԫ������
            return false;
        }
        DlinkListNode* node = new DlinkListNode(value);
        if (size == 0) {
            //˫�˶�����û��Ԫ��
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == capacity) {
            return false;
        }
        DlinkListNode* node = new DlinkListNode(value);
        if (size == 0) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (size == 0) {
            //û��Ԫ��
            return false;
        }
        auto node = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete(node);
        size--;
        return true;
    }

    bool deleteLast() {
        if (size == 0) {
            //û��Ԫ��
            return false;
        }
        auto node = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        delete(node);
        size--;
        return true;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->val;
    }

    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};