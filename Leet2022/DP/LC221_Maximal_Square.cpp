class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        const int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = 1;
                if (i == 0 || j == 0) {
                    
                } else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        }
        return ans;
    }
};
