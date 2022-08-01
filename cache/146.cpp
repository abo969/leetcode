/**
 * 146. LRU 缓存
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 实现 LRUCache 类：
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * https://leetcode.cn/problems/lru-cache/
 */

class LRUCache {
private:
    // 双向链表节点
    struct LinkNode {
        int key, val;
        LinkNode* prev;
        LinkNode* next;

        LinkNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
        LinkNode(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;   // cache容量
    int size;       // 当前item个数

    LinkNode* head; // 双向链表头，虚拟节点
    LinkNode* tail; // 双向链表尾，虚拟节点

    // LRU cache
    unordered_map<int, LinkNode*> cache;

public:
    void push_front(LinkNode* node) {   // 链表头加一个节点
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }

    void remove(LinkNode* node) {       // 从链表删除指点节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LinkNode* pop_back() {              // 删除尾节点
        LinkNode* node = tail->prev;
        remove(node);
        return node;
    }

    void move_front(LinkNode* node) {   // 将指定节点移到表头
        remove(node);                   // 先删除该节点
        push_front(node);               // 将该节点加入链表头
    }

    void update(int key, int val) {     // 更新cache
        LinkNode* node = cache[key];
        node->val = val;
        move_front(node);               // 将更新的节点移到表头
    }

    void eliminate() {                  // 淘汰最早使用的
        LinkNode* node = pop_back();    // 删除尾节点
        cache.erase(node->key);         // 删除cache项
        delete node;                    // 释放内存
        --size;                         // 更新当前个数
    }

    // cache构造，初始化一个cache
    LRUCache(int cap) : capacity(cap), size(0) {
        head = new LinkNode();
        tail = new LinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;

        LinkNode* node = cache[key];
        move_front(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {        // cache中不存在该key
            LinkNode* node = new LinkNode(key, value);
            cache[key] = node;          // 加入cache

            push_front(node);           // 最近使用的放在链表头
            size++;

            if (size > capacity) {
                eliminate();            // 淘汰最早使用项
            }
        } else {                        // key已存在
            update(key, value);         // 更新cache
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */