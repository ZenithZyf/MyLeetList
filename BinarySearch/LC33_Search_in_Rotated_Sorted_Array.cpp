class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) {
            return -1;
        }
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] >= nums[l]) {
                if (nums[m] > target && nums[l] <= target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] < target && nums[r] >= target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
