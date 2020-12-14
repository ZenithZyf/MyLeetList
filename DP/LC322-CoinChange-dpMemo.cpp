class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {   
        vector<int> memo(amount + 1, -2);
        std::sort(coins.rbegin(), coins.rend());
        
        return dfs(coins, amount, memo);
    }
private:
    int dfs(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        
        if (memo[amount] != -2) return memo[amount];
        
        int res = 99999;
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                int sub_optimal = dfs(coins, amount - coin, memo);
                if (sub_optimal == -1) continue;
                res = std::min(res, sub_optimal + 1);
            }
        }
        
        if (res == 99999) {
            memo[amount] = -1;
            return -1;
        }
        
        memo[amount] = res;
        return res;
    }
};
