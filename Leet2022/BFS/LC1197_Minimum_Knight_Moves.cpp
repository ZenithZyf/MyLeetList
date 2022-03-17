class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = std::abs(x);
        y = std::abs(y);
        queue<vector<int>> q;
        q.push({0, 0});
        const vector<vector<int>> dirs = {{2, 1}, {2, -1}, {1, 2}, {1, -2},
                                          {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        int steps = 0;
        vector<vector<bool>> visited(302, vector<bool>(302, false));
        visited[0][0] = true;
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto cur = q.front(); q.pop();
                const int cur_x = cur[0];
                const int cur_y = cur[1];
                if (cur_x == x && cur_y == y) {
                    return steps;
                }
                for (auto& d : dirs) {
                    const int new_x = cur_x + d[0];
                    const int new_y = cur_y + d[1];
                    // const string new_str = std::to_string(new_x) + "," + std::to_string(new_y);
                    if (new_x >= -1 && new_y >= -1 && new_x <= 300 && new_y <= 300 && !visited[new_x + 1][new_y + 1]) {
                        q.push({new_x, new_y});
                        visited[new_x + 1][new_y + 1] = true;
                    }
                }
            }
            ++steps;
        }
        
        return 0;
    }
};
