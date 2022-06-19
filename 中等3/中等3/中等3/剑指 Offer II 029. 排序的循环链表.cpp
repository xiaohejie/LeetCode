#include<iostream>
using namespace std;

/*
    剑指 Offer II 029. 排序的循环链表
*/
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return head;
        }
        //找到一个结点，该节点小于等于insertVal，该节点的下一个结点大于等于insertVal
        Node* cur = head;
        Node* next = cur->next;
        while (next != head)
        {
            if ((cur->val <= insertVal && next->val >= insertVal)) {
                //进行插入
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            //还有一种情况，insertVal是最小的数或最大的数
            if (cur->val > next->val && cur->val >= insertVal && next->val >= insertVal) {
                //进行插入
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            if (cur->val > next->val && cur->val <= insertVal && next->val <= insertVal) {
                //进行插入
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            //否则的话，遍历下一个点
            cur = next;
            next = next->next;
        }
        //如果当next到head点
        //进行插入
        cur->next = newNode;
        newNode->next = next;
        return head;
    }
};