class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;    
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
          auto it = lower_bound(begin(dp), end(dp), nums[i]);
          if (it == end(dp))
            dp.push_back(nums[i]);
          else
            *it = nums[i];
        }
        return dp.size();
    }
};
