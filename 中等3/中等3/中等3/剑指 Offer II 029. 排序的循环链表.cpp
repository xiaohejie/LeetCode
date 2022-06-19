#include<iostream>
using namespace std;

/*
    ��ָ Offer II 029. �����ѭ������
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
        //�ҵ�һ����㣬�ýڵ�С�ڵ���insertVal���ýڵ����һ�������ڵ���insertVal
        Node* cur = head;
        Node* next = cur->next;
        while (next != head)
        {
            if ((cur->val <= insertVal && next->val >= insertVal)) {
                //���в���
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            //����һ�������insertVal����С������������
            if (cur->val > next->val && cur->val >= insertVal && next->val >= insertVal) {
                //���в���
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            if (cur->val > next->val && cur->val <= insertVal && next->val <= insertVal) {
                //���в���
                cur->next = newNode;
                newNode->next = next;
                break;
            }
            //����Ļ���������һ����
            cur = next;
            next = next->next;
        }
        //�����next��head��
        //���в���
        cur->next = newNode;
        newNode->next = next;
        return head;
    }
};