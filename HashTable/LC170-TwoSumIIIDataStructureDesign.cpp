class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto m : mp) {
            long remain = value - m.first;
            if ((remain != m.first && mp.count(remain)) || (remain == m.first && mp[remain] > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<long, long> mp;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
