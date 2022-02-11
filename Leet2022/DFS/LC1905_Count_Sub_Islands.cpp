class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int m = grid1.size(), n = grid1[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(grid2, i, j);
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    ++res;
                    dfs(grid2, i, j);
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, const int i, const int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        return;
    }
};
