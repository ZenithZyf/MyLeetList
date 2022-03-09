class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> nums(ranges.size());
        for (int i = 0; i <= n; ++i) {
            int s = max(0, i - ranges[i]);
            nums[s] = max(nums[s], i + ranges[i]);
        }
        int steps = 0;
        int l = 0;
        int e = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > e) {
                return -1;
            }
            if (i > l) {
                l = e;
                ++steps;
            }
            e = max(e, nums[i]);
        }
        return steps;
    }
};
