#include<iostream>
#include<queue>
using namespace std;
/*
	116. 填充每个节点的下一个右侧节点指针
        进行广度优先遍历
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        //生成队列
        queue<Node* > que;
        que.push(root); //放入头结点
        while (!que.empty()) {
            int count = que.size();
            while (count) {
                Node* newNode = que.front();
                que.pop();
                if (newNode->left) {
                    que.push(newNode->left);
                }
                if (newNode->right) {
                    que.push(newNode->right);
                }
                if (count == 1) {
                    //如果该行只剩一个节点
                    newNode->next = nullptr;
                }
                else {
                    //不止一个节点，next指向该节点的下一个结点
                    newNode->next = que.front();
                }
                count--;
            }
        }
        return root;
    }
};
