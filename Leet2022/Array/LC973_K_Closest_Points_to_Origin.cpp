class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](pair<int, int> p1, pair<int, int> p2) { return p1.first > p2.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            int idx = pq.top().second; pq.pop();
            res.push_back(points[idx]);
        }
        return res;
    }
};
