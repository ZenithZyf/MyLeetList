class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    res += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};
