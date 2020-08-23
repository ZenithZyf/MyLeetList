class Solution {
public:
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        return dfs(maze, m, n, start[0], start[1], destination[0], destination[1]);
    }
private:
    bool dfs(vector<vector<int>>& maze, int m, int n, int i, int j, int di, int dj) {
        if (i == di && j == dj) return true;
        bool res = false;
        maze[i][j] = -1;
        for (auto dir : dirs) {
            int y = i;
            int x = j;
            while (y >= 0 && y < m && x >= 0 && x < n && maze[y][x] != 1) {
                y += dir[0];
                x += dir[1];
            }
            y -= dir[0]; x -= dir[1];
            if (maze[y][x] != -1) {
                res |= dfs(maze, m, n, y, x, di, dj);
            }
        }
        return res;

    }
};
