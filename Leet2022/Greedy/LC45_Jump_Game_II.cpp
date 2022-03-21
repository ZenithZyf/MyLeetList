class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int jumps = 0;
        int end = 0;
        int far = 0;
        for (int i = 0; i < n - 1; ++i) {
            far = std::max(nums[i] + i, far);
            if (end == i) {
                jumps++;
                end = far;
            }
        }
        return jumps;
    }
};
