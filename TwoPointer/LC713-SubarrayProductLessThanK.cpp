class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            if (product < k)
                ans += right - left + 1;
            else {
                while (product >= k && left <= right) {
                    product /= nums[left];
                    left++;
                }
                ans += right - left + 1;
            }
        }
        
        return ans;
    }
};
