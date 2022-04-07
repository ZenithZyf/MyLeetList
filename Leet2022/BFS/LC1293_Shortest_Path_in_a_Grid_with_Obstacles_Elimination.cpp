class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        q.push({0, 0, 0});
        int steps = 0;
        vector<vector<int>> seen(m, vector<int>(n, INT_MAX));
        const vector<int> dirs{0, -1, 0, 1, 0};
        seen[0][0] = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                vector<int> cur = q.front(); q.pop();
                if (cur[0] == m - 1 && cur[1] == n - 1) {
                    return steps;
                }
                for (int i = 0; i < 4; ++i) {
                    const int cur_row = cur[0] + dirs[i];
                    const int cur_col = cur[1] + dirs[i + 1];
                    if (cur_row < 0 || cur_row >= m || cur_col < 0 || cur_col >= n) {
                        continue;
                    }
                    int curk = cur[2] + grid[cur_row][cur_col];
                    if (curk >= seen[cur_row][cur_col] || curk > k) {
                        continue;
                    }
                    seen[cur_row][cur_col] = curk;
                    q.push({cur_row, cur_col, curk});
                }
            }
            ++steps;
        }
        return -1;
    }
};
