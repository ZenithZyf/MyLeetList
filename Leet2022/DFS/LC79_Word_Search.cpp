class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (dfs(board, word, 0, m, n, j, i)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, const string& word, const int d, const int m, const int n, const int y, const int x) {
        if (x < 0 || x == n || y < 0 || y == m || word[d] != board[y][x]) {
            return false;
        }
        if (d == word.length() - 1) {
            return true;
        }
        char cur = board[y][x];
        board[y][x] = '0';
        bool found = dfs(board, word, d + 1, m, n, y, x - 1)
                  || dfs(board, word, d + 1, m, n, y, x + 1)
                  || dfs(board, word, d + 1, m, n, y - 1, x)
                  || dfs(board, word, d + 1, m, n, y + 1, x);
        board[y][x] = cur;
        return found;
    }
};
