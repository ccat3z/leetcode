#include <iostream>
#include <unordered_map>
#include <vector>

#define DUMP

class LRUCache {
public:
    LRUCache(int capacity) {
        pool = new ValueNode[capacity + 2];
        pool[0].next = 1;
        pool[1].prev = 0;
        pool_next = 2;
        pool_cap = capacity + 2;
    }

    ~LRUCache() {
        delete [] pool;
    }
    
    int get(int key) {
        auto slot = find(key);
        if (slot >= 0) {
            drop(slot);
            prepend(slot);
            dump();
            return pool[slot].value;
        }

        dump();
        return -1;
    }
    
    void put(int key, int value) {
        auto slot = find(key);
        if (slot >= 0) {
            pool[slot].value = value;
            drop(slot);
            prepend(slot);
            dump();
            return;
        }

        if (pool_next == pool_cap) {
            slot = pool[1].prev;
            drop(slot);
        } else {
            slot = pool_next++;
        }

        pool[slot].key = key;
        pool[slot].value = value;
        prepend(slot);

        map[key] = slot;

        dump();
    }

    int find(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        auto node = it->second;
        if (pool[node].key == key) {
            return node;
        } else {
            return -1;
        }
    }

    void prepend(int node) {
        pool[node].next = pool[0].next;
        pool[pool[node].next].prev = node;

        pool[0].next = node;
        pool[node].prev = 0;
    }

    void drop(int node) {
        auto prev = pool[node].prev;
        auto next = pool[node].next;

        pool[prev].next = next; 
        pool[next].prev = prev;
    }

    void dump() {
#ifdef DUMP
        size_t i = pool[0].next;
        std::cerr << "[";
        while (i != 1) {
            std::cerr << '(' << pool[i].key << ',' << pool[i].value << ')' << ',';
            i = pool[i].next;
        }
        std::cerr << "]" << std::endl;
#endif
    }

    struct ValueNode {
        size_t prev;
        size_t next;
        int key;
        int value;
    };
    ValueNode *pool;
    size_t pool_next;
    size_t pool_cap;

    std::unordered_map<int, int> map;
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cerr << lru.get(1) << std::endl;
    lru.put(3, 3);
    std::cerr << lru.get(2) << std::endl;
    lru.put(1, 2);
    return 0;
}