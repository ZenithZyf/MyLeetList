class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> coordinates;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    coordinates.push({i, j});
                    seen[i][j] = 1;
                }
            }
        }
        
        vector<int> dir{0, -1, 0, 1, 0};
        int steps = 0;
        while (!coordinates.empty()) {
            int size = coordinates.size();
            while (size--) {
                auto pair = coordinates.front(); coordinates.pop();
                int i = pair.first;
                int j = pair.second;
                ans[i][j] = steps;
                for (int k = 0; k < 4; ++k) {
                    int x = j + dir[k];
                    int y = i + dir[k + 1];
                    if (x < 0 || x >= n || y < 0 || y >= m || seen[y][x]) {
                        continue;
                    }
                    seen[y][x] = 1;
                    coordinates.push({y, x});
                }
            }
            ++steps;
        }
        
        return ans;
    }
};
