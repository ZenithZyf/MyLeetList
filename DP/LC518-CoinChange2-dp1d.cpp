class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // sort(coins.begin(), coins.end());
        
        for (int coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i < coin)
                    continue;
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
        
    }
};
