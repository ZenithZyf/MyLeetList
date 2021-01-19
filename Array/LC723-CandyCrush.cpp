class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        while (true) {
            vector<pair<int, int>> del;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) {
                        continue;
                    }
                    int x0 = i, x1 = i;
                    int y0 = j, y1 = j;
                    int val = board[i][j];
                    while (x0 < m && x0 < i + 3 && board[x0][j] == val) ++x0;
                    while (x1 >= 0 && x1 > i - 3 && board[x1][j] == val) --x1;
                    while (y0 < n && y0 < j + 3 && board[i][y0] == val) ++y0;
                    while (y1 >= 0 && y1 > j - 3 && board[i][y1] == val) --y1;
                    if (x0 - x1 > 3 || y0 - y1 > 3) del.push_back({i, j});
                }
            }
            if (del.empty()) break;
            for (auto d : del) board[d.first][d.second] = 0;
            for (int j = 0; j < n; j++) {
                int t = m - 1;
                for (int i = m - 1; i >= 0; i--) {
                    if (board[i][j] != 0) {
                        swap(board[t][j], board[i][j]);
                        t--;
                    }
                }
            }
        }
        return board;
    }
};
