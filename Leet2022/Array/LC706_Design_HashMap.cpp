class MyHashMap {
public:
    MyHashMap() {
        data_.resize(1001, vector<int>());
    }
    
    void put(int key, int value) {
        int hash_key = key % 1000;
        if (data_[hash_key].empty()) {
            data_[hash_key].resize(1001, -1);
        }
        data_[hash_key][key / 1000] = value;
    }
    
    int get(int key) {
        int hash_key = key % 1000;
        if (!data_[hash_key].empty()) {
            return data_[hash_key][key / 1000];
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = key % 1000;
        if (!data_[hash_key].empty()) {
            data_[hash_key][key / 1000] = -1;
        }
    }
private:
    vector<vector<int>> data_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
