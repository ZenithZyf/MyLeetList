class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstPos(nums, target), secondPos(nums, target)};
    }
private:
    int firstPos(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        if (l == nums.size() || nums[l] != target) return -1;
        return l;
    }
    
    int secondPos(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        if (l == 0 || nums[l - 1] != target) return -1;
        return l - 1;
    }
};
