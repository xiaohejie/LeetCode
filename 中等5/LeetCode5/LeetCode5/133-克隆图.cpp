#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	133. ��¡ͼ
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
    //�����ϣ��ʾԭʼ�ڵ��뿽���ڵ��ӳ���ϵ
    unordered_map<Node*, Node*> map;
    void dfs(Node* node) {
        //����ӳ���ϵ
        map[node] = new Node(node->val);
        //�ж��ڽӵ���û�б����ʹ�
        for (auto& n : node->neighbors) {
            if (!map[n]) {
                //û�з��ʹ�
                dfs(n);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        //����ԭʼ���뿽�����ӳ���ϵ
        dfs(node);
        //�������������֮��Ĺ�ϵ
        for (auto& [pre, m] : map) {
            for (auto& n : pre->neighbors) {
                m->neighbors.push_back(map[n]);
            }
        }
        return map[node];
    }
};