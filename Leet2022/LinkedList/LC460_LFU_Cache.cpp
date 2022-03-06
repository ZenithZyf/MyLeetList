struct CacheNode {
    int key;
    int value;
    int freq;
    // pointer to the node in the list.
    list<int>::const_iterator it;
};

class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
        min_freq_ = 0;
    }
    
    int get(int key) {
        auto it = n_.find(key);
        if (it == n_.cend()) {
            return -1;
        }
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) {
            return;
        }
        
        auto it = n_.find(key);
        if (it != n_.cend()) {
            // Key exists, update value and touch it
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if (n_.size() == capacity_) {
            // No Space, need to remove 1
            // 1. lowest freq
            // 2. least recently used
            
            // Remove the element from min_freq_list
            const int key_to_evict = l_[min_freq_].back();
            l_[min_freq_].pop_back();
            
            // Remove the key from cache
            n_.erase(key_to_evict);
        }
        
        const int freq = 1;
        min_freq_ = freq;
        
        // Add the key to the freq list
        l_[freq].push_front(key);
        
        // Create a new node
        n_[key] = {key, value, freq, l_[freq].cbegin()};
    }
private:
    int capacity_;
    int min_freq_;
    // key -> CacheNode
    unordered_map<int, CacheNode> n_;
    // freq -> keys
    unordered_map<int, list<int>> l_;
    
    void touch(CacheNode& node) {
        // Update the freq
        const int prev_freq = node.freq;
        const int freq = ++(node.freq);
        
        // Remove the entry from old freq list
        l_[prev_freq].erase(node.it);
        
        if (l_[prev_freq].empty() && prev_freq == min_freq_) {
            // Delete the list
            l_.erase(prev_freq);
            
            // Increase min_freq_
            ++min_freq_;
        }
        
        // Insert key to the front of the new freq list
        l_[freq].push_front(node.key);
        
        // Update the pointer
        node.it = l_[freq].cbegin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
