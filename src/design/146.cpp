// 146. LRU 缓存
// https://leetcode.cn/problems/lru-cache/
// tags: 设计
// tips: 哈希表 + 双向链表

#include "common.h"

struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    int capacity{0};
    int size{0};
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head{nullptr};
    DLinkedNode* tail{nullptr};

    LRUCache(int capacity) : capacity(capacity) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            DLinkedNode* node = new DLinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            size++;
            if (size > capacity) {
                DLinkedNode* tail = removeTail();
                cache.erase(tail->key);
                delete tail;
                size--;
            }
        }
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

};
