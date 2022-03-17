class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        // key: presum; val: times occurred
        unordered_map<int, int> pre_sum;
        pre_sum[0] = 1;
        
        int sum_0i = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            sum_0i += nums[i];
            int sum_0j = sum_0i - k;
            if (pre_sum[sum_0j]) {
                res += pre_sum[sum_0j];
            }
            ++pre_sum[sum_0i];
        }
        return res;
    }
};
