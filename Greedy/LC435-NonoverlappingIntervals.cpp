class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& nums1, vector<int>& nums2)-> bool {
            return nums1[1] < nums2[1];
        });
        
        int cnt = 1;
        int prev_end = intervals[0][1];
        for (auto interval : intervals) {
            int start = interval[0];
            if (start >= prev_end) {
                cnt++;
                prev_end = interval[1];
            }
        }
        
        return intervals.size() - cnt;
    }
};
