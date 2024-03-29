class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        std::sort(jobs.begin(), jobs.end());
        
        int ans = 0;
        map<int, int> m{{0, 0}}; // end_time -> max_profit
        for (const auto& job : jobs) {
            int p = prev(m.upper_bound(job[1]))->second + job[2];
            if (p > rbegin(m)->second) {
                m[job[0]] = p;
            }
        }
        return rbegin(m)->second;
    }
};
