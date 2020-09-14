class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        else {
            int prev = nums[0];
            int cur = max(prev, nums[1]);
            for (int i = 2; i < nums.size(); ++i) {
                int tmp = cur;
                cur = max(prev + nums[i], cur);
                prev = tmp;
            }
            return cur;
        }
        
        return 0;
    }
};
