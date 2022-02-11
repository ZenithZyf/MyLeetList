class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        int res = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, const int i, const int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1) {
            return;
        }
        
        grid[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return;
    }
};
