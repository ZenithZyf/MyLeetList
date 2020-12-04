class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // if (n == 1) return nums;
        quick(nums, 0, n - 1);
        return nums;
    }
private:
    void quick(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivot = left;
        int i = left;
        int j = right;
        while (i < j) {
            while (i < j && nums[j] > nums[pivot]) j--;
            while (i < j && nums[i] <= nums[pivot]) i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int temp = nums[j];
        nums[j] = nums[pivot];
        nums[pivot] = temp;
        quick(nums, left, j - 1);
        quick(nums, j + 1, right);
        return;
    }
};
