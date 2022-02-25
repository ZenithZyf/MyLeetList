class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 4, 0, target);
    }
private:
    vector<vector<int>> nSum(const vector<int>& nums, const int n, const int start, const int target) {
        const int sz = nums.size();
        vector<vector<int>> res_;
        if (sz < n || n < 2) {
            return res_;
        }
        if (n == 2) {
            int lo = start, hi = sz - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target) {
                    while (lo < hi && nums[lo] == left) ++lo;
                } else if (sum > target) {
                    while (lo < hi && nums[hi] == right) --hi;
                } else {
                    res_.push_back({left, right});
                    while (lo < hi && nums[lo] == left) ++lo;
                    while (lo < hi && nums[hi] == right) --hi;
                }
            }
        } else {
            for (int i = start; i < sz; ++i) {
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& arr : sub) {
                    arr.emplace_back(nums[i]);
                    res_.emplace_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1]) ++i;
            }
        }
        return res_;
    }
};
