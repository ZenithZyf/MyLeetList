class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector<int> p(n);
        iota(begin(p), end(p), 0);
        
        for (const auto& c : connections)
            p[find(p, c[0])] = find(p, c[1]);
        
        unordered_set<int> s;
        for (int i = 0; i < n; ++i)
            s.insert(find(p, i));
        
        return s.size() - 1;
        
    }
private:
    int find(vector<int>& p, int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return p[x];
    }
};
