class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }
            if (nums[start] < nums[mid]) {
                if (nums[mid] > target && nums[start] <= target)
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                if (nums[mid] < target && nums[end] >= target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};
