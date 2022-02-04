class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board_ = vector<string>(n, string(n, '.'));
        backtrack(0);
        return sol_;
    }

private:
    vector<vector<string>> sol_;
    vector<string> board_;
    
    void backtrack(int row) {
        if (row == board_.size()) {
            sol_.emplace_back(board_);
            return;
        }
        
        for (int i = 0; i < board_.size(); ++i) {
            if (!isValid(row, i)) {
                continue;
            }
            board_[row][i] = 'Q';
            backtrack(row + 1);
            board_[row][i] = '.';
        }
    }
    
    bool isValid(int row, int col) {
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board_[i][j] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col; i >= 0; --i) {
            if (board_[i][j] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < board_.size(); --i, ++j) {
            if (board_[i][j] == 'Q') return false;
        }
        
        return true;
    }
};
