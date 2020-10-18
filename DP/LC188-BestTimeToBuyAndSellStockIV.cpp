class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        
        int n = prices.size();
        
        if (k > n / 2) {
            int prof = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    prof += prices[i] - prices[i - 1];
            return prof;
        }
        
        vector<int> buy(k + 1, -prices[0]);
        vector<int> sell(k + 1, 0);
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                buy[j - 1] = std::max(buy[j - 1], sell[j - 1] - prices[i]);
                sell[j] = std::max(sell[j], buy[j - 1] + prices[i]);
            }
        }
        
        return sell[k];
        
    }
};
