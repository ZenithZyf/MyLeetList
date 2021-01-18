class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        vector<vector<pair<int, int>>> v(A.size(), vector<pair<int, int>>());
        for (int i = 0; i < A.size(); i++) {
            for (int k = 0; k < A[i].size(); k++) {
                if (A[i][k] != 0) {
                    int val = A[i][k];
                    for (int j = 0; j < B[0].size(); ++j) {
                        res[i][j] += val * B[k][j];
                    }
                }
            }
        }
        
        // for (int i = 0; i < A.size(); i++) {
        //     for (int k = 0; k < v[i].size(); k++) {
        //         int col = v[i][k].first;
        //         int val = v[i][k].second;
        //         for (int j = 0; j < B[0].size(); ++j) {
        //             res[i][j] += val * B[col][j];
        //         }
        //     }
        // }
        return res;
    }
};
