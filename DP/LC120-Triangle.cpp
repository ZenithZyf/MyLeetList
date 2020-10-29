class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int d = triangle.size();
        if (d == 0) return 0;
        
        for (int i = 1; i < d; i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        
        for (int i = 2; i < d; i++) {
            for (int j = 1; j < i; j++)
                triangle[i][j] += std::min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        
        return *std::min_element(triangle[d - 1].begin(), triangle[d - 1].end());
    }
};
