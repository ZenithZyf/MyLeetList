class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; ++i) {
            vector<vector<int>> twoNums = twoSum(nums, i + 1, 0 - nums[i]);
            for (vector<int>& twoNum : twoNums) {
                twoNum.emplace_back(nums[i]);
                res.emplace_back(twoNum);
            }
            while (i < n - 2 && nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
private:
    vector<vector<int>> twoSum(const vector<int> nums, const int start, const int target) {
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) ++lo;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) --hi;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) ++lo;
                while (lo < hi && nums[hi] == right) --hi;
            }
        }
        return res;
    }
};
