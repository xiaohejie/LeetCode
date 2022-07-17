#include<iostream>
using namespace std;
/*
	558. �Ĳ�����������427�������Ĳ������ƣ�
        ���δ���
        �ݹ�
        
*/

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

/*����һ*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        //���quadTree1��Ҷ�ӽ��
        if (quadTree1->isLeaf) {
            //�ж�val�Ƿ���1������ǣ��ͷ���1
            if (quadTree1->val) {
                return new Node(true, true);
            }
            //������ǣ��ͷ���quadTree2�Ľ��
            return new Node(quadTree2->val, quadTree2->isLeaf, quadTree2->topLeft, quadTree2->topRight, quadTree2->bottomLeft, quadTree2->bottomRight);
        }
        //�ж�quadTree2�Ƿ���Ҷ�ӽ��
        if (quadTree2->isLeaf) {
            return intersect(quadTree2, quadTree1);
        }
        //���quadTree1��quadTree2������Ҷ�ӽ��
        //�ֱ��ж������������������ĸ��ڵ�
        Node* n1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* n2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* n3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* n4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        //�����ж�
        if (n1->isLeaf&&n2->isLeaf&&n3->isLeaf&&n4->isLeaf&&n1->val==n2->val&&n1->val==n3->val&&n1->val== n4->val) {
            return new Node(n1->val,true);
        }
        else {
            return new Node(false, false, n1, n2, n3, n4);
        }
    }
};

/*������*/
class Solution {
public:
    Node* intersect(Node* T1, Node* T2) {
        //T1��T2������һ����Ҷ�ӽ��
        if (T1->isLeaf && T1->val == 0)return T2;
        if (T1->isLeaf && T1->val == 1)return T1;
        if (T2->isLeaf && T2->val == 0)return T1;
        if (T2->isLeaf && T2->val == 1)return T2;
        //������������
        /*
            ��ͨ���ݹ�õ�res
            Ȼ���ж��Ƿ���Ҷ�ӽ��{
                res�����ֵ�Ƿ����{
                    ��ȵĻ�������new Node(res->topLeft->val, true);
                }
            }����Ļ�{
                return res;
            }
        */
        Node* res = new Node(false, false, intersect(T1->topLeft, T2->topLeft), intersect(T1->topRight, T2->topRight), intersect(T1->bottomLeft, T2->bottomLeft), intersect(T1->bottomRight, T2->bottomRight));
        if (res->topLeft->isLeaf && res->topRight->isLeaf && res->bottomLeft->isLeaf && res->bottomRight->isLeaf)
            if (res->topLeft->val == res->topRight->val && res->topLeft->val == res->bottomRight->val && res->topLeft->val == res->bottomLeft->val)
                return new Node(res->topLeft->val, true);
        return res;
    }
};