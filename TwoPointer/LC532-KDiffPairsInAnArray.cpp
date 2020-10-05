class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() < 2) return 0;
        std::sort(nums.begin(), nums.end());
        int cnt = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - k > nums[i]) {
                    break;
                }
                if (nums[j] - k == nums[i]) {
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};
