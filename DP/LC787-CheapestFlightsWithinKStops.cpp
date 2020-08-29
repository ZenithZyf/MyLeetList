class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        constexpr int kInfCost = 1e9;
        vector<int> cost(n, kInfCost);
        cost[src] = 0;
        
        for (int i = 0; i <= K; ++i) {
            vector<int> tmp(cost);
            for (const auto& f : flights) {
                tmp[f[1]] = std::min(tmp[f[1]], cost[f[0]] + f[2]);
            }
            cost.swap(tmp);
        }
        
        return cost[dst] >= kInfCost ? -1 : cost[dst];
    }
};
