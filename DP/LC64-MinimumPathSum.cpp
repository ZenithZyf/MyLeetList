class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        for (int i = 1; i < m; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int y = 1; y < n; y++)
            for (int x = 1; x < m; x++)
                grid[y][x] += std::min(grid[y - 1][x], grid[y][x - 1]);
        return grid[n - 1][m - 1];
    }
};
