class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> graph(N+1);
        for (const auto& t : trust) {
            --graph[t[0]];
            ++graph[t[1]];
        }
        for (int i = 1; i <= N; ++i) {
            if (graph[i] == N - 1) return i;
        }
        return -1;
    }
};
