class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // dp[x]: length of "Longest Arithmetic Subsequence" ends with number x;
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : arr) {
            ans = max(ans, dp[x] = dp[x - difference] + 1);
        }
        return ans;
    }
};
