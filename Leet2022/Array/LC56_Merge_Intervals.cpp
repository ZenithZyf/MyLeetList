class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        vector<vector<int>> ans;
        int small = intervals[0][0], big = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= big) {
                big = std::max(big, intervals[i][1]);
            } else {
                ans.push_back({small, big});
                small = intervals[i][0];
                big = intervals[i][1];
            }
        }
        ans.push_back({small, big});
        return ans;
    }
};
