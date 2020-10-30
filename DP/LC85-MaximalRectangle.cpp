class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int len = INT_MAX;
                for (int k = i; k < m; ++k) {
                    len = std::min(len, dp[k][j]);
                    if (len == 0) break;
                    ans = std::max(len * (k - i + 1), ans);
                }
            }
        
        return ans;
    }
};
