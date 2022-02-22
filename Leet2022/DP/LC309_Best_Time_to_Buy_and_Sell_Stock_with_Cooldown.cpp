/*
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 2][k - 1][0] - prices[i])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            if (i == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
