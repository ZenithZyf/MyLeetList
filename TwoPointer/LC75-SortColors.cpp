class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int red = 0;
        int blue = n - 1;
        for (int ptr = 0; ptr <= blue; ptr++) {
            if (nums[ptr] == 0) {
                swap(nums[ptr], nums[red]);
                red++;
            } else if (nums[ptr] == 2) {
                swap(nums[ptr], nums[blue]);
                blue--;
                ptr--;
            }
        }
        return;
    }
};
