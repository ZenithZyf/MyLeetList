class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        const int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
