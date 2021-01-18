class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> g(n, vector<int>(3, 0));
        vector<vector<int>> l(n, vector<int>(3, 0));
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; j++) {
                l[i][j] = max(g[i - 1][j - 1] + (diff > 0 ? diff : 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};
