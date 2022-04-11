class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int n = intervals.size();
        const int m = queries.size();
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
           return a[1] > b[1]; 
        });
        vector<pair<int, int>> qs(m);
        for (int i = 0; i < m; ++i) {
            qs[i] = {queries[i], i};
        }
        sort(qs.rbegin(), qs.rend());
        
        vector<int> ans(m);
        int j = 0;
        priority_queue<pair<int, int>> pq;
        for (const auto& [query, i] : qs) {
            while (j < n && intervals[j][1] >= query) {
                pq.emplace(-(intervals[j][1] - intervals[j][0] + 1), intervals[j][0]);
                ++j;
            }
            while (!pq.empty() && pq.top().second > query) {
                pq.pop();
            }
            ans[i] = pq.empty() ? -1 : -pq.top().first;
        }
        return ans;
    }
};
