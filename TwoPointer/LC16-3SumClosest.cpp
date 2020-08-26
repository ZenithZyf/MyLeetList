class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = target;
        int d = INT_MAX;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            int s = i + 1;
            int e = n - 1;
            while (s < e) {
                int tmp = nums[i] + nums[s] + nums[e];
                if (tmp == target)
                    return target;
                
                if (abs(tmp - target) < d) {
                    d = abs(tmp - target);
                    ans = tmp;
                }
                
                if (tmp < target)
                    ++s;
                else
                    --e;
            }
        }
        
        return ans;
    }
};
