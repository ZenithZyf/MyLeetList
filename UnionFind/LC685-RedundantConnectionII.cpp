class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parents(edges.size() + 1, 0);
        vector<int> roots(edges.size() + 1, 0);
        vector<int> sizes(edges.size() + 1, 1);
        
        vector<int> ans1;
        vector<int> ans2;
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            
            if (parents[v] > 0) {
                ans1 = {parents[v], v};
                ans2 = e;
                
                e[0] = e[1] = -1;
            }
            
            parents[v] = u;
        }
        
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            
            if (u < 0 || v < 0) continue;
            
            if (!roots[u]) roots[u] = u;
            if (!roots[v]) roots[v] = v;
            int pu = find(u, roots);
            int pv = find(v, roots);
            
            if (pu == pv)
                return ans1.empty() ? e : ans1;
            
            if (sizes[pv] > sizes[pu])
                swap(pu, pv);
            
            roots[pv] = pu;
            sizes[pu] += sizes[pv];
        }
        
        return ans2;
    }
private:
    int find(int node, vector<int>& roots) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
};
