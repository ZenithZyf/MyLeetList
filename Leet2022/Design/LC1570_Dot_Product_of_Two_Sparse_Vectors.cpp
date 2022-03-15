class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                index[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        unordered_map<int, int> oIndex = vec.index;
        int res = 0;
        for (auto& it : index) {
            if (oIndex[it.first]) {
                res += it.second * oIndex[it.first];
            }
        }
        return res;
    }
private:
    unordered_map<int, int> index;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
