class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        for (int mm = 0; mm < m; mm++) {
            if (obstacleGrid[mm][0] == 1)
                break;
            dp[mm][0] = 1;
        }
        for (int nn = 0; nn < n; nn++) {
            if (obstacleGrid[0][nn] == 1)
                break;
            dp[0][nn] = 1;
        }
        
        for (int y = 1; y < m; y++)
            for (int x = 1; x < n; x++) {
                if (obstacleGrid[y][x] == 1)
                    continue;
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
            }
        
        return dp[m - 1][n - 1];
    }
};
