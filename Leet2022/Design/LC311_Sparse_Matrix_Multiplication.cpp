class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector<int>> res(mat1.size(), vector<int>(mat2[0].size(), 0));
        vector<vector<pair<int, int>>> v(mat1.size(), vector<pair<int, int>>());
        for (int i = 0; i < mat1.size(); ++i) {
            for (int j = 0; j < mat1[0].size(); ++j) {
                if (mat1[i][j] != 0) {
                    v[i].push_back({j, mat1[i][j]});
                }
            }
        }
        for (int i = 0; i < mat1.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                int col = v[i][j].first;
                int val = v[i][j].second;
                for (int k = 0; k < mat2[0].size(); ++k) {
                    res[i][k] += mat2[col][k] * val;
                }
            }
        }
        return res;
    }
};
