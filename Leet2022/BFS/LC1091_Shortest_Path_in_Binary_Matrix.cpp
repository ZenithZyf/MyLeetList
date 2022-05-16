class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int res = 0, n = grid.size();
        queue<vector<int>> q;
        q.push({0, 0});
        vector<vector<int>> dirs{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            ++res;
            for (int i = q.size(); i > 0; --i) {
                auto t = q.front(); q.pop();
                if (t[0] == n - 1 && t[1] == n - 1) {
                    return res;
                }
                for (auto dir : dirs) {
                    int x = t[0] + dir[0], y = t[1] + dir[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1 || grid[x][y] == 2) {
                        continue;
                    }
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};
