class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        sort(coins.begin(), coins.end());
        
        for (int k = 0; k <= coins.size(); k++) {
            dp[k][0] = 1;
        }
        
        for (int k = 1; k <= coins.size(); k++) {
            for (int i = 1; i <= amount; i++) {
                int coin = coins[k - 1];
                if (coin > i)
                    dp[k][i] = dp[k - 1][i];
                else
                    dp[k][i] = dp[k - 1][i] + dp[k][i - coin];
                
            }
        }
        
        return dp[coins.size()][amount];
        
    }
};
