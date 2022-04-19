class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }
        const int m = mat.size(), n = mat[0].size();
        int res = 0;
        const vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, -1}, {-1, 1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int cnt = 0;
                    int x = i, y = j;
                    while (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 1) {
                        x += dirs[k][0];
                        y += dirs[k][1];
                        ++cnt;
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};
