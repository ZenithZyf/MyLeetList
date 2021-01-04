class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            res = max(res, cur_sum);
        }
        return res;
    }
};
