class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int m = board.size(), n = board[0].size();
        function<void(int, int)> dfs = [&](int x, int y) {
            if (board[y][x] != 'E') {
                return;
            }
            int c = 0;
            for (int tx = x - 1; tx <= x + 1; ++tx) {
                for (int ty = y - 1; ty <= y + 1; ++ty) {
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        c += board[ty][tx] == 'M';
                    }
                }
            }
            if (c > 0) {
                board[y][x] = '0' + c;
                return;
            }
            board[y][x] = 'B';
            for (int tx = x - 1; tx <= x + 1; ++tx) {
                for (int ty = y - 1; ty <= y + 1; ++ty) {
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        dfs(tx, ty);
                    }
                }
            }
        };
        int x = click[1];
        int y = click[0];
        dfs(x, y);
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
        }
        return board;
    }
};
