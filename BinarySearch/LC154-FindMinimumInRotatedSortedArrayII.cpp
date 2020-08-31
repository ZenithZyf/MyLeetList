class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
private:
    int findMin(vector<int>& nums, int l, int r) {
        if (l+1 >= r) return min(nums[l], nums[r]);
        if (nums[l] < nums[r]) return nums[l];
        int m = l + (r-l)/2;
        return min(findMin(nums, l, m-1),
                   findMin(nums, m, r));
    }
};
