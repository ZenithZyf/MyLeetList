class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> ts(n, INT_MAX);
        vector<vector<int>> ans;
        int t = 0;
        
        function<int(int, int)> tarjan = [&](int i, int p) {
            int min_i = ts[i] = ++t;
            for (int j : graph[i]) {
                if (ts[j] == INT_MAX) {
                    int min_j = tarjan(j, i);
                    min_i = min(min_j, min_i);
                    if (ts[i] < min_j)
                        ans.push_back({i, j});
                } else if (j != p) {
                    min_i = min(min_i, ts[j]);
                }
            }
            return min_i;
        };
        
        for (const auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        tarjan(0, -1);
        
        return ans;
    }
};
