class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        if (n == 0) return 0;
        
        vector<int> sTime;
        vector<int> eTime;
        for (int i = 0; i < n; ++i) {
            sTime.push_back(intervals[i][0]);
            eTime.push_back(intervals[i][1]);
        }
        
        std::sort(sTime.begin(), sTime.end());
        std::sort(eTime.begin(), eTime.end());
        
        int sPtr = 0;
        int ePtr = 0;
        int num = 0;
        
        while (sPtr < n) {
            if (sTime[sPtr] >= eTime[ePtr]) {
                num--;
                ePtr++;
            }
            num++;
            sPtr++;
        }
        
        return num;
    }
};
