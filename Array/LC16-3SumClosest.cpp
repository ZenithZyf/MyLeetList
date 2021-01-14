class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cloest = nums[0] + nums[1] + nums[2];
        int diff = abs(target - cloest);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (nums[i] * 3 > target) {
                return min(cloest, nums[i] + nums[i + 1] + nums[i + 2]);
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < diff) {
                    diff = abs(nums[i] + nums[l] + nums[r] - target);
                    cloest = nums[i] + nums[l] + nums[r];
                }
                if (nums[i] + nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return cloest;
    }
};
