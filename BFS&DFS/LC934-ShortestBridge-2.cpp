class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        queue<pair<int, int>> que;
        
        bool flag = false;
        for (int i = 0; i < m && !flag; i++) {
            for (int j = 0; j < n && !flag; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, que);
                    flag = true;
                }
            }
        }
        
        int steps = 0;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        while (!que.empty()) {
            int s = que.size();
            while (s--) {
                auto point = que.front(); que.pop();
                int x = point.first;
                int y = point.second;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dirs[i];
                    int ny = y + dirs[i + 1];
                    if (nx < 0 || nx == A[0].size() || ny < 0 || ny == A.size() || A[ny][nx] == 2)
                        continue;
                    if (A[ny][nx] == 1)
                        return steps;
                    A[ny][nx] = 2;
                    que.push({nx, ny});
                }
            }
            steps++;
        }
        return -1;
    }
private:
    void dfs(vector<vector<int>>& A, int y, int x, queue<pair<int, int>>& que) {
        if (x < 0 || x == A[0].size() || y < 0 || y == A.size() || A[y][x] != 1)
            return;
        
        A[y][x] = 2;
        que.push({x, y});
        
        dfs(A, y - 1, x, que);
        dfs(A, y + 1, x, que);
        dfs(A, y, x - 1, que);
        dfs(A, y, x + 1, que);
    }
};
