class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++) {
                int start = A[i - 1][j];
                if (j > 0)
                    start = std::min(start, A[i - 1][j - 1]);
                if (j < m - 1)
                    start = std::min(start, A[i - 1][j + 1]);
                A[i][j] += start;
            }
        
        return *std::min_element(begin(A.back()), end(A.back()));
    }
};
