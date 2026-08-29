class LRUCache {
private:
    int capacity;
    unordered_map<int, int> kv;                     // key -> value
    unordered_map<int, list<int>::iterator> pos;   // key -> iterator in list
    list<int> lru;                                 // keys in order (front = LRU)

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end()) return -1;

        // Move key to end (most recently used)
        lru.erase(pos[key]);
        lru.push_back(key);
        pos[key] = prev(lru.end());  // O(1), no insert needed

        return it->second;
    }

    void put(int key, int value) {
        if (auto it = kv.find(key); it != kv.end()) {
            // Update existing key
            it->second = value;
            lru.erase(pos[key]);
            lru.push_back(key);
            pos[key] = prev(lru.end());
        } else {
            // New key
            if (kv.size() >= capacity) {
                // Evict LRU
                int old_key = lru.front();
                kv.erase(old_key);
                pos.erase(old_key);
                lru.pop_front();  // O(1)
            }
            // Insert new
            kv[key] = value;
            lru.push_back(key);
            pos[key] = prev(lru.end());
        }
    }
};