class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        return nums;
    }
};
