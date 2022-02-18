class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q_boarder;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'E';
                q_boarder.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'E';
                q_boarder.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = 'E';
                q_boarder.push({0, j});
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = 'E';
                q_boarder.push({m - 1, j});
            }
        }
        const vector<int> dirs{0, -1, 0, 1, 0};
        while (!q_boarder.empty()) {
            auto cur = q_boarder.front(); q_boarder.pop();
            int r = cur.first;
            int c = cur.second;
            for (int i = 0; i < 4; ++i) {
                int y = r + dirs[i];
                int x = c + dirs[i + 1];
                if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] == 'X' || board[y][x] == 'E') {
                    continue;
                }
                q_boarder.push({y, x});
                board[y][x] = 'E';
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};
