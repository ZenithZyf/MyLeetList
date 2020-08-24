class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int a = 0;
        int b = 0;
        vector<vector<int>> ans;
        while (a < A.size() && b < B.size()) {
            const int s = max(A[a][0], B[b][0]);
            const int e = min(A[a][1], B[b][1]);
            if (s <= e) {
                ans.push_back({s, e});
            }
            if (A[a][1] < B[b][1])
                ++a;
            else
                ++b;
        }
        return ans;
    }
};
