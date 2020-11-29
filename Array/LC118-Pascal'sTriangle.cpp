class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return {};
        if (numRows == 1) {
            return {{1}};
        }
        if (numRows == 2) {
            return {{1}, {1, 1}};
        }
        res.push_back({1});
        res.push_back({1, 1});
        for (int i = 2; i < numRows; i++) {
            vector<int> a(i + 1, 1);
            res.push_back(a);
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        
        return res;
    }
};
