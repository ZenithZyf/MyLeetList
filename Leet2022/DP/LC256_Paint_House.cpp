class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        const int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        for (int i = 0; i < 3; ++i) {
            dp[0][i] = costs[0][i];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        int res = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};
