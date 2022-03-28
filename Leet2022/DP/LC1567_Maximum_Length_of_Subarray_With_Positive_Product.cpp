class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int l1 = 0, l0 = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                l1 = 0;
                l0 = 0;
            }
            if (nums[i] > 0) {
                ++l1;
                l0 = l0 == 0 ? 0 : l0 + 1;
            }
            if (nums[i] < 0) {
                int tmp = l1;
                l1 = l0 == 0 ? 0 : l0 + 1;
                l0 = tmp + 1;
            }
            ans = max(l1, ans);
        }
        return ans;
    }
};
