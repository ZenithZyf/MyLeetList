class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) continue;
                
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    ans += 1;
                } else {
                    dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    ans += dp[i][j];
                }
            }
        return ans;
    }
};
