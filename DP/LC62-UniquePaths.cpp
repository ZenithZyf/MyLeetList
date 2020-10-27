class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int mm = 0; mm < m; mm++)
            dp[mm][0] = 1;
        for (int nn = 0; nn < n; nn++)
            dp[0][nn] = 1;
        
        for (int y = 1; y < m; y++)
            for (int x = 1; x < n; x++)
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
        
        return dp[m - 1][n - 1];
    }
};
