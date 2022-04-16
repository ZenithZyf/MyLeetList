class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            res = min(res, nums[n - 4 + i] - nums[i]);
        }
        return res;
    }
};
