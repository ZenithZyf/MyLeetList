class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> human{};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    human.push({i, j});
                    grid[i][j] = 'X';
                    break;
                }
            }
        }
        const vector<int> dirs = {0, -1, 0, 1, 0};
        int steps = 1;
        while (!human.empty()) {
            int sz = human.size();
            for (int k = 0; k < sz; ++k) {
                auto cur = human.front(); human.pop();
                int row = cur.first;
                int col = cur.second;
                for (int i = 0; i < 4; ++i) {
                    int y = row + dirs[i];
                    int x = col + dirs[i + 1];
                    if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == 'X') {
                        continue;
                    }
                    if (grid[y][x] == '#') {
                        return steps;
                    }
                    grid[y][x] = 'X';
                    human.push({y, x});
                }
            }
            ++steps;
        }
        return -1;
    }
};
