class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        set<string> sqs;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    string sq;
                    dfs(grid, i, j, sq, 6);
                    if (!sqs.count(sq)) {
                        ++res;
                        sqs.insert(sq);
                    }
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, const int i, const int j, string& sq, const int dir) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0;
        sq += dir;
        sq += ',';
        
        dfs(grid, i + 1, j, sq, 1);
        dfs(grid, i - 1, j, sq, 2);
        dfs(grid, i, j + 1, sq, 3);
        dfs(grid, i, j - 1, sq, 4);
        
        sq += -dir;
        sq += ',';
    }
};
