class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int num = nums.back();
        m[num] = m[val];
        nums[m[val]] = num;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
