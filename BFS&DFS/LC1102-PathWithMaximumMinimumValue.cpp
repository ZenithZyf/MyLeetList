class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[0][0] = 1;
        priority_queue<Point> pq;
        pq.push(Point(0, 0, A[0][0]));
        int res = min(A[0][0], A[m - 1][n - 1]);
        while (!pq.empty()) {
            Point p = pq.top(); pq.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.x + dirs[i][0];
                int y = p.y + dirs[i][1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    res = min(res, p.val);
                    if (x == m - 1 && y == n - 1) return res;
                    visited[x][y] = 1;
                    pq.push(Point(x, y, A[x][y]));
                }
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
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};
