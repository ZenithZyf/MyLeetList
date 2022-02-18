class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        priority_queue<Point> pq;
        pq.push(Point(0, 0, grid[0][0]));
        int res = min(grid[0][0], grid[m - 1][n - 1]);
        const vector<int> dirs{0, -1, 0, 1, 0};
        while (!pq.empty()) {
            Point cur = pq.top(); pq.pop();
            res = min(res, cur.val);
            for (int i = 0; i < 4; ++i) {
                const int dx = dirs[i];
                const int dy = dirs[i + 1];
                int x = cur.x + dx;
                int y = cur.y + dy;
                if (x < 0 || x >= n || y < 0 || y >= m || visited[y][x]) {
                    continue;
                }
                if (x == n - 1 && y == m - 1) {
                    return res;
                }
                visited[y][x] = 1;
                pq.push(Point(x, y, grid[y][x]));
            }
        }
        return res;
    }
private:
    struct Point {
        int x, y, val;
        Point(int x_, int y_, int val_) : x(x_), y(y_), val(val_) {}
        bool operator < (const Point& other) const {
            return this->val < other.val;
        }
    };
};
