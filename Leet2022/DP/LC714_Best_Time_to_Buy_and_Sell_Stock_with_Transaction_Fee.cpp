class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size();
        int dp_sell = 0, dp_buy = -INT_MAX;
        for (int i = 0; i < n; ++i) {
            dp_sell = max(dp_sell, dp_buy + prices[i]);
            dp_buy = max(dp_buy, dp_sell - prices[i] - fee);
        }
        return dp_sell;
    }
};
