#include<iostream>
#include<unordered_map>
using namespace std;
/*
	146. LRU 缓存
        使用链表进行缓存
*/
struct Node {
    int val;
    int key;
    Node* prev;
    Node* next;
    Node():val(0), key(0), prev(nullptr), next(nullptr) {}
    Node(int _val, int _key) : val(_val), key(_key), prev(nullptr), next(nullptr) {}
};
class LRUCache {
    int size;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;
public:
    LRUCache(int _capacity): size(0), capacity(_capacity) {
        // 使用伪头部和伪尾部节点
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //查找哈希表中有没有key
        if (!map.count(key)) {
            return -1;
        }
        //如果key存在，先通过哈希表定位，再移到头部
        Node* node = map[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            //key已经存在
            Node* node = map[key];
            node->val = value;
            moveToHead(node);
        }
        else {
            //key不存在，就进行插入
            Node* node = new Node(value, key);
            //添加进哈希表
            map[key] = node;
            //添加至双向链表的头部
            addToHead(node);
            size++;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                Node* removed = removeTail();
                // 删除哈希表中对应的项
                map.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
    }
    //定义链表的插入和删除
    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};