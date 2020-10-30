class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        // dp[i][j].first = min steps to reach i, j (tail pos) facing right
        // dp[i][j].second = min steps to reach i, j (tail pos) facing down
        // ans = dp[n][n - 1].first
        
        constexpr int kInf = 1e9;
        const int n = grid.size();
        vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n + 1, {kInf, kInf}));
        dp[0][1].first = dp[1][0].first = -1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                bool h = false;
                bool v = false;
                if (!grid[i - 1][j - 1] && j < n && !grid[i - 1][j]) {
                    dp[i][j].first = min(dp[i - 1][j].first, dp[i][j - 1].first) + 1;
                    h = true;
                }
                if (!grid[i - 1][j - 1] && i < n && !grid[i][j - 1]) {
                    dp[i][j].second = min(dp[i - 1][j].second, dp[i][j - 1].second) + 1;
                    v = true;
                }
                if (v && j < n && !grid[i][j])
                    dp[i][j].second = min(dp[i][j].second, dp[i][j].first + 1);
                if (h && i < n && !grid[i][j])
                    dp[i][j].first = min(dp[i][j].first, dp[i][j].second + 1);
            }
        }
        return dp[n][n-1].first >= kInf ? -1 : dp[n][n - 1].first;
    }
};
