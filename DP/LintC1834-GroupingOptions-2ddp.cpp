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
        
        // dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
        // dp[i-1][j-1]: first group of people is 1
        // dp[i-j][j]: first group of people is larger than 1
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= std::min(i, m); j++) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            }
        }
        
        return dp[n][m];
    }
};
