class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob_nocircle(nums, 0, nums.size() - 2),
                   rob_nocircle(nums, 1, nums.size() - 1));
    }
private:
    int rob_nocircle(vector<int>& nums, const int start, const int end) {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = end; i >= 0; --i) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[start];
    }
};
