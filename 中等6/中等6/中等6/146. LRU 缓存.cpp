#include<iostream>
#include<unordered_map>
using namespace std;
/*
	146. LRU ����
        ʹ��������л���
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
        // ʹ��αͷ����αβ���ڵ�
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        //���ҹ�ϣ������û��key
        if (!map.count(key)) {
            return -1;
        }
        //���key���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
        Node* node = map[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            //key�Ѿ�����
            Node* node = map[key];
            node->val = value;
            moveToHead(node);
        }
        else {
            //key�����ڣ��ͽ��в���
            Node* node = new Node(value, key);
            //��ӽ���ϣ��
            map[key] = node;
            //�����˫�������ͷ��
            addToHead(node);
            size++;
            if (size > capacity) {
                // �������������ɾ��˫�������β���ڵ�
                Node* removed = removeTail();
                // ɾ����ϣ���ж�Ӧ����
                map.erase(removed->key);
                // ��ֹ�ڴ�й©
                delete removed;
                --size;
            }
        }
    }
    //��������Ĳ����ɾ��
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