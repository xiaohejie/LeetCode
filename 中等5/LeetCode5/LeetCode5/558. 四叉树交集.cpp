#include<iostream>
using namespace std;
/*
	558. 四叉树交集（与427、建立四叉树类似）
        分治处理
        递归
        
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

/*方法一*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        //如果quadTree1是叶子结点
        if (quadTree1->isLeaf) {
            //判断val是否是1，如果是，就返回1
            if (quadTree1->val) {
                return new Node(true, true);
            }
            //如果不是，就返回quadTree2的结果
            return new Node(quadTree2->val, quadTree2->isLeaf, quadTree2->topLeft, quadTree2->topRight, quadTree2->bottomLeft, quadTree2->bottomRight);
        }
        //判断quadTree2是否是叶子结点
        if (quadTree2->isLeaf) {
            return intersect(quadTree2, quadTree1);
        }
        //如果quadTree1和quadTree2都不是叶子结点
        //分别判断两棵树的上下左右四个节点
        Node* n1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* n2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* n3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* n4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        //进行判断
        if (n1->isLeaf&&n2->isLeaf&&n3->isLeaf&&n4->isLeaf&&n1->val==n2->val&&n1->val==n3->val&&n1->val== n4->val) {
            return new Node(n1->val,true);
        }
        else {
            return new Node(false, false, n1, n2, n3, n4);
        }
    }
};

/*方法二*/
class Solution {
public:
    Node* intersect(Node* T1, Node* T2) {
        //T1和T2其中有一个是叶子结点
        if (T1->isLeaf && T1->val == 0)return T2;
        if (T1->isLeaf && T1->val == 1)return T1;
        if (T2->isLeaf && T2->val == 0)return T1;
        if (T2->isLeaf && T2->val == 1)return T2;
        //若两个都不是
        /*
            先通过递归得到res
            然后判断是否是叶子结点{
                res里面的值是否相等{
                    相等的话，返回new Node(res->topLeft->val, true);
                }
            }否则的话{
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