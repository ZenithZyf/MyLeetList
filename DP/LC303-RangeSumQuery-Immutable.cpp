class NumArray {
public:
    NumArray(vector<int>& nums): preSum_(nums) {
        if (nums.empty()) return;
        for (int i = 1; i < nums.size(); i++)
            preSum_[i] += preSum_[i - 1];
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return preSum_[j];
        return preSum_[j] - preSum_[i - 1];
    }
    
private:
    vector<int> preSum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
