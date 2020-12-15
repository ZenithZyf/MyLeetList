class Solution {
public:
    /**
     * @param n: the number of people
     * @param m: the number of groups
     * @return: the number of grouping options
     */
    long long groupingOptions(int n, int m) {
        // write your code here
        if (n < m) return (long long)(0);
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            dp[i][i] = 1;
        }
        
        // dp[i][j] = sum_k(dp[i - j][k]) (base group dp[i][i])
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= std::min(i, m); j++) {
                for (int k = 1; k <= j; k++) {
                    dp[i][j] += dp[i - j][k];
                }
            }
        }
        
        return dp[n][m];
    }
};
