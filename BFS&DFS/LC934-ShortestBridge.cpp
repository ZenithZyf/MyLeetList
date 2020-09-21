class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        queue<pair<int, int>> q;
        
        bool found = false;
        for (int y = 0; y < m && !found; ++y) {
            for (int x = 0; x < n && !found; ++x) {
                if (A[y][x] == 1) {
                    dfs(A, x, y, q);
                    found = true;
                }
            }
        }
        
        int steps = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front(); q.pop();
                int x = p.first;
                int y = p.second;
                for (int i = 0; i < 4; ++i) {
                    int tx = x + dirs[i];
                    int ty = y + dirs[i + 1];
                    if (tx < 0 || ty < 0 || tx == n || ty == m || A[ty][tx] == 2)
                        continue;
                    if (A[ty][tx] == 1)
                        return steps;
                    A[ty][tx] = 2;
                    q.push({tx, ty});
                }
            }
            steps++;
        }
        
        return -1;
    }
private:
    void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
        if (x < 0 || x == A[0].size() || y < 0 || y == A.size() || A[y][x] != 1)
            return;
        
        A[y][x] = 2;
        q.push({x, y});
        dfs(A, x - 1, y, q);
        dfs(A, x + 1, y, q);
        dfs(A, x, y - 1, q);
        dfs(A, x, y + 1, q);
    }
};
