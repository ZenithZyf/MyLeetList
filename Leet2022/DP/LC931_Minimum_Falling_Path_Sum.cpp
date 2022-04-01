class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        // if (n == 1) {
        //     return *min_element(matrix[0].begin(), matrix[0].end());
        // }
        vector<int> dp(matrix[0]);
        for (int i = 1; i < n; ++i) {
            int prev = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int start = dp[j];
                if (j > 0) {
                    start = std::min(start, prev);
                }
                prev = dp[j];
                if (j < n - 1) {
                    start = std::min(start, dp[j + 1]);
                }
                dp[j] = matrix[i][j] + start;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
