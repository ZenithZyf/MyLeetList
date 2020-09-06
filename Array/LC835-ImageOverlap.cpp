class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ans = 0;
        vector<int> flat_a, flat_b;
        unordered_map<int, int> vec_cnt;
        
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++) {
                if (A[r][c] == 1) flat_a.push_back(flat(r, c));
                if (B[r][c] == 1) flat_b.push_back(flat(r, c));
            }
        
        for (const auto& a : flat_a)
            for (const auto& b : flat_b)
                ++vec_cnt[a - b];
        
        for (const auto& c : vec_cnt)
            ans = std::max(ans, c.second);
        
        return ans;
    }
private:
    static inline int flat(const int r, const int c) { return (r << 6) + c; };
};
