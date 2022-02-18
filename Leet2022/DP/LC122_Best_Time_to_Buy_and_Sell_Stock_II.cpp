/*
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i - 1]);
k = k - 1; since infinite
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
