class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        constexpr int MAX = 1e5 + 1;
        vector<vector<int>> left(MAX);
        for (int i = 0; i < events.size(); ++i) {
            left[events[i][0]].emplace_back(i);
        }
        int res = 0;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int i = 1; i < MAX; ++i) {
            for (int j = 0; j < left[i].size(); ++j) {
                pq.push(events[left[i][j]][1]);
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++res;
                pq.pop();
            }
        }
        return res;
    }
};
