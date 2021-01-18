class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n;) {
            int j = i + 1;
            int t = intervals[i][1];
            while (j < n && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], t});
            i = j;
        }
        return res;
    }
};
