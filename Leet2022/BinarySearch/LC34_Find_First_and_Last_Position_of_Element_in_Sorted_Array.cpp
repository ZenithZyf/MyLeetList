class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {leftBound(nums, target), rightBound(nums, target)};
    }
private:
    int leftBound(const vector<int>& nums, const int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) {
            return -1;
        }
        return left;
    }
    
    int rightBound(const vector<int>& nums, const int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (right < 0 || nums[right] != target) {
            return -1;
        }
        return right;
    }
};
