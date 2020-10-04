class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return 1;
        
        std::sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int left = 0;
        int right = 1;
        
        while (right < n) {
            // while (right < n && intervals[right][1] <= intervals[left][1]) {
            //     cnt++;
            //     right++;
            // }
            // left = right++;
            if (intervals[left][0] == intervals[right][0]
             && intervals[left][1] <= intervals[right][1]) {
                left++;
                right++;
                cnt++;
                continue;
            }
            if (intervals[left][1] >= intervals[right][1]) {
                right++;
                cnt++;
                continue;
            }
            left = right++;
        }
        
        return n - cnt;
    }
};
