class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        
        long long mod = t + 1LL;
        unordered_map<long long, long long> buck;
        for (int i = 0; i < nums.size(); ++i) {
            long long nth = nums[i] / mod;
            if (nums[i] < 0) nth--;
            if (buck.find(nth) != buck.end())
                return true;
            else if (buck.find(nth - 1) != buck.end() && abs(nums[i] - buck[nth - 1]) <= t)
                return true;
            else if (buck.find(nth + 1) != buck.end() && abs(nums[i] - buck[nth + 1]) <= t)
                return true;
            buck[nth] = nums[i];
            if (i >= k) {
                buck.erase(nums[i - k] / mod);
            }
        }
        return false;
        
    }
};
