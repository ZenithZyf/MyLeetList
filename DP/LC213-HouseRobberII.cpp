class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return std::max(rob(nums, 0, n - 2),
                        rob(nums, 1, n - 1));
    }
private:
    int rob(vector<int>& nums, int start, int end) {
        int prev = 0;
        int curr = 0;
        
        for (int i = start; i <= end; ++i) {
            int tmp = curr;
            curr = std::max(curr, prev + nums[i]);
            prev = tmp;
        }
        
        return curr;
        
    }
};
