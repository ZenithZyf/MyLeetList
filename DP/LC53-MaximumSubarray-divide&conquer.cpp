class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int left, int right) {
        if (left >= right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int lmax = helper(nums, left, mid);
        int rmax = helper(nums, mid + 1, right);
        int mmax = nums[mid];
        int t = mmax;
        for (int i = mid - 1; i >= left; i--) {
            t += nums[i];
            mmax = max(t, mmax);
        }
        t = mmax;
        for (int i = mid + 1; i <= right; i++) {
            t += nums[i];
            mmax = max(t, mmax);
        }
        return max(mmax, max(lmax, rmax));
    }
};
