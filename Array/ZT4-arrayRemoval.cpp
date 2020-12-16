class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int k = target;
        vector<int> preMax(n, 0);
        vector<int> preMin(n, 0);
        vector<int> postMax(n, 0);
        vector<int> postMin(n, 0);
        
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > tmp) {
                tmp = nums[i];
            }
            preMax[i] = tmp;
        }
        
        tmp = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] < tmp) {
                tmp = nums[i];
            }
            preMin[i] = tmp;
        }
        
        tmp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > tmp) {
                tmp = nums[i];
            }
            postMax[i] = tmp;
        }
        
        tmp = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < tmp) {
                tmp = nums[i];
            }
            postMin[i] = tmp;
        }
        
        int diff = INT_MAX;
        for (int i = 0; i <= n - k; i++) {
            if (i - 1 < 0) {
                diff = std::min(diff, postMax[i + k] - postMin[i + k]);
            } else if (i + k == n) {
                diff = std::min(diff, preMax[i - 1] - preMin[i - 1]);
            } else {
                int curMax = std::max(preMax[i - 1], postMax[i + k]);
                int curMin = std::min(preMin[i - 1], postMin[i + k]);
                diff = std::min(diff, curMax - curMin);
            }
        }
        
        return {0, 0};
    }
};
