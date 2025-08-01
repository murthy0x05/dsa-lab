class LRUCache {
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int capacity;
public:
    LRUCache(int capacity) {
        cache.resize(capacity);
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            cache.push_front(make_pair((*map[key]).first, (*map[key]).second));
            cache.erase(map[key]);
            map[key] = cache.begin();
            return (*map[key]).second;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();    
        } else {
            if (cache.size() < capacity) {
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            } else {
                map.erase(cache.back().first);
                cache.pop_back();
                cache.push_front(make_pair(key, value));
                map[key] = cache.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */