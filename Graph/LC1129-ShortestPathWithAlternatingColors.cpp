class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<unordered_set<int>> edges_r(n);
        vector<unordered_set<int>> edges_b(n);
        
        for (const auto& e : red_edges)
            edges_r[e[0]].insert(e[1]);
        for (const auto& e : blue_edges)
            edges_b[e[0]].insert(e[1]);
        
        unordered_set<int> visited_r;
        unordered_set<int> visited_b;
        
        vector<int> ans(n, -1);
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        visited_r.insert(0);
        visited_b.insert(0);
        
        int step = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int p = q.front().first;
                int color = q.front().second;
                q.pop();
                ans[p] = ans[p] >= 0 ? min(ans[p], step) : step;
                const auto& edges = color ? edges_r : edges_b;
                auto& visited = color ? visited_r : visited_b;
                for (int nxt : edges[p]) {
                    if (visited.count(nxt)) continue;
                    visited.insert(nxt);
                    q.push({nxt, 1 - color});
                }
            }
            ++step;
        }
        return ans;
    }
};
