#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
	133. 克隆图
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
    //定义哈希表示原始节点与拷贝节点的映射关系
    unordered_map<Node*, Node*> map;
    void dfs(Node* node) {
        //建立映射关系
        map[node] = new Node(node->val);
        //判断邻接点有没有被访问过
        for (auto& n : node->neighbors) {
            if (!map[n]) {
                //没有访问过
                dfs(n);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        //建立原始点与拷贝点的映射关系
        dfs(node);
        //建立拷贝点的线之间的关系
        for (auto& [pre, m] : map) {
            for (auto& n : pre->neighbors) {
                m->neighbors.push_back(map[n]);
            }
        }
        return map[node];
    }
};