class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            
            unordered_set<int> visited;
            if (hasPath(u, v, graph, visited))
                return e;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool hasPath(int u, int v, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        if (u == v) return true;
        visited.insert(u);
        if (!graph.count(u) || !graph.count(v)) return false;
        for (int nxt : graph.at(u)) {
            if (visited.count(nxt)) continue;
            if (hasPath(nxt, v, graph, visited)) return true;
        }
        return false;
    }
};
