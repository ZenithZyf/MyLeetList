class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = std::max(ans[i - 1] + nums[i], nums[i]);
        }
        
        return *std::max_element(ans.begin(), ans.end());
    }
};
