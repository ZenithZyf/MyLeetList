class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag = false;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
                continue;
            } 
            
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                flag = true;
                for (int j = i; j < intervals.size(); ++j)
                    ans.push_back(intervals[j]);
                break;
            }
            
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
        
        if (!flag)
            ans.push_back(newInterval);
        
        return ans;
    }
};
