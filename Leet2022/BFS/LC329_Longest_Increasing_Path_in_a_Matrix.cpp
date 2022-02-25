class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }
        const int m = mat.size(), n = mat[0].size();
        int res = 1;
        vector<vector<int>> dp_table(m, vector<int>(n, 0));
        const vector<int> dirs = {0, -1, 0, 1, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp_table[i][j] > 0) {
                    continue;
                }
                queue<pair<int, int>> longest_q;
                longest_q.push({i, j});
                int steps = 1;
                while (!longest_q.empty()) {
                    ++steps;
                    int sz = longest_q.size();
                    for (int ll = 0; ll < sz; ++ll) {
                        auto cur = longest_q.front(); longest_q.pop();
                        for (int kk = 0; kk < 4; ++kk) {
                            int yy = cur.first + dirs[kk];
                            int xx = cur.second + dirs[kk + 1];
                            if (yy < 0 || yy >= m || xx < 0 || xx >= n || mat[yy][xx] <= mat[cur.first][cur.second] || steps <= dp_table[yy][xx]) {
                                continue;
                            }
                            dp_table[yy][xx] = steps;
                            res = max(res, steps);
                            longest_q.push({yy, xx});
                        }
                    }
                }                 
            }
        }

        return res;
    }
};
