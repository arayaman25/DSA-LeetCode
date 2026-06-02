#include<iostream>
using namespace std;
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            m.erase(key);

            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return res;
        }
        return -1; // If not found
    }
    
    void put(int key, int value) {

        if (m.find(key) != m.end()) { //key already exists
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }

        if (m.size() == cap) { //capacity already reached
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */