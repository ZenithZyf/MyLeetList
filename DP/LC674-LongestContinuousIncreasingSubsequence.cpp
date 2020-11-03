class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n =  nums.size();
        if (n == 0) return 0;
        int prev = INT_MIN;
        int ans = 0;
        int cnt = 0;
        for (int num : nums) {
            if (prev < num) {
                cnt++;
            } else {
                cnt = 1;
            }
            prev = num;
            ans = std::max(ans, cnt);
        }
        return ans;
    }
};
