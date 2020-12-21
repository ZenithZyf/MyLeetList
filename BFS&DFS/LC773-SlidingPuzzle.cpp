class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2;
        int n = 3;
        string start = "";
        string target = "123450";
        
        // switch our starting status to a string
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start.push_back(board[i][j] + '0');
            }
        }
        
        // index for possible moving index
        // after we flatten the 2D matrix to a 1D vector
        vector<vector<int>> neighbor = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {4, 2}
        };
        
        // start bfs
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                // whether we reached the target or not
                if (target == cur) {
                    return step;
                }
                // find the index of number 0
                int idx = 0;
                for(; cur[idx] != '0'; idx++);
                // switch 0 and the neighbors
                for (int adj : neighbor[idx]) {
                    string new_board = cur;
                    swap(new_board[adj], new_board[idx]);
                    if (!visited.count(new_board)) {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
