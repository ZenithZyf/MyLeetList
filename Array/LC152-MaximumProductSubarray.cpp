class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tmp_large = 1;
        int tmp_small = 1;
        int large = INT_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                int tmp = tmp_large;
                tmp_large = tmp_small;
                tmp_small = tmp;
            }
            tmp_large = std::max(nums[i], tmp_large * nums[i]);
            tmp_small = std::min(nums[i], tmp_small * nums[i]);
            large = std::max(large, tmp_large);
        }
        
        return large;
    }
};
