class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        vector<int> visited(n, 0);
        int connected = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            dfs(graph, visited, i);
            ++connected;
        }
        return connected;
    }
private:
    void dfs(const vector<vector<int>>& graph, vector<int>& visited, const int i) {
        if (visited[i]) {
            return;
        }
        visited[i] = 1;
        for (int j = 0; j < graph[i].size(); ++j) {
            dfs(graph, visited, graph[i][j]);
        }
        return;
    }
};
