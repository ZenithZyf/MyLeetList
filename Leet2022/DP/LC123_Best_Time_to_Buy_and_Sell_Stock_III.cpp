/*
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] + prices[i])
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        const int k_max = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k_max + 1, vector<int>(2, 0)));
        
        for (int i = 0; i < n; ++i) {
            for (int k = k_max; k >= 1; --k) {
                if (i == 0) {
                    // dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        
        return dp[n - 1][k_max][0];
    }
};
