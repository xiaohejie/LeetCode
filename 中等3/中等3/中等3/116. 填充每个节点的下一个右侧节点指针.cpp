#include<iostream>
#include<queue>
using namespace std;
/*
	116. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ��
        ���й�����ȱ���
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
        //���ɶ���
        queue<Node* > que;
        que.push(root); //����ͷ���
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
                    //�������ֻʣһ���ڵ�
                    newNode->next = nullptr;
                }
                else {
                    //��ֹһ���ڵ㣬nextָ��ýڵ����һ�����
                    newNode->next = que.front();
                }
                count--;
            }
        }
        return root;
    }
};
