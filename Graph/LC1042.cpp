class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, 0);
        vector<vector<int>> G(N);
        for (const auto& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        
        
        for (int i = 0; i < N; ++i) {
            int mask = 0;
            for (const auto& j : G[i])
                mask |= (1 << ans[j]);
            for (int c = 1; c <= 4 && ans[i] == 0; ++c)
                if (!(mask & (1 << c))) ans[i] = c;
        }
        return ans;
    }
};
