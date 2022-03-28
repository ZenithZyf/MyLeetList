class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int total = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++total;
                } else if (grid[i][j] == 2) {
                    ++total;
                    q.push({i, j});
                }
            }
        }
        if (total == 0) {
            return 0;
        }
        int time = 0;
        int rotted = 0;
        const vector<int> dirs = {0, -1, 0, 1, 0};
        while (!q.empty()) {
            int sz = q.size();
            rotted += sz;
            while (sz-- > 0) {
                auto cur = q.front(); q.pop();
                for (int i = 0; i < 4; ++i) {
                    const int new_row = cur.first + dirs[i];
                    const int new_col = cur.second + dirs[i + 1];
                    if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n && grid[new_row][new_col] == 1) {
                        q.push({new_row, new_col});
                        grid[new_row][new_col] = 2;
                    }
                }
            }
            ++time;
        }
        return total == rotted ? --time : -1;
    }
};
