class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if (n == 0) {
            return 0;
        }
        if (k > n / 2) {
            return maxProfitInf(prices);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i) {
            dp[i][0][1] = -INT_MAX;
            // dp[i][0][0] = 0;
        }
        for (int j = k; j >= 1; --j) {
            dp[0][j][1] = -prices[0];
            // dp[0][j][0] = 0;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j >= 1; --j) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
private:
    int maxProfitInf(const vector<int>& prices) {
        const int n = prices.size();
        int dp_sell = 0;
        int dp_buy = -INT_MAX;
        for (int i = 0; i < n; ++i) {
            dp_sell = max(dp_sell, dp_buy + prices[i]);
            dp_buy = max(dp_buy, dp_sell - prices[i]);
        }
        return dp_sell;
    }
};
