class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {   
        vector<int> dp(amount + 1, amount + 1);
        for (auto coin : coins) {
            if (coin <= amount)
                dp[coin] = 1;
        }
        
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != amount + 1) {
                    dp[i] = std::min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        return dp[amount] == amount + 1 ? -1 : dp[amount];
        
    }
};
