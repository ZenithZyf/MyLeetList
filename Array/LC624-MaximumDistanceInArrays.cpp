class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int start = arrays[0][0];
        int end = arrays[0][arrays[0].size() - 1];
        int res = 0;
        
        for (int i = 1; i < arrays.size(); ++i) {
            int n = arrays[i].size();
            res = std::max(res, std::max(abs(arrays[i][n - 1] - start), abs(end - arrays[i][0])));
            start = std::min(start, arrays[i][0]);
            end = std::max(end, arrays[i][n - 1]);
        }
        
        return res;
    }
};
