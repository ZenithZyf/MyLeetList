class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        constexpr int MAX_TIME = 100 * 101;
        vector<int> dist(N, MAX_TIME);
        dist[K - 1] = 0;
        
        for (int i = 0; i < N; ++i) {
            for (const auto& time : times) {
                int u = time[0] - 1;
                int v = time[1] - 1;
                int t = time[2];
                
                dist[v] = std::min(dist[v], dist[u]+t);
            }
        }
        
        int max_dist = *std::max_element(begin(dist), end(dist));
        return max_dist == MAX_TIME ? -1 : max_dist;
        
    }
};
