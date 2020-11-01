class Solution {
public:
    int numTilings(int N) {
        constexpr int kMod = 1000000007;
        // dp[i][0]: ways to cover i cols, both rows of col i are covered;
        // dp[i][1]: ways to cover i cols, top rows of col i are covered;
        // dp[i][2]: ways to cover i cols, bottom rows of col i are covered.
        // Since dp[i][1] and dp[i][2] are the same, we can simplify it.
        vector<vector<long>> dp(N + 1, vector<long>(2, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 1][1]) % kMod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
        }
        return dp[N][0];
    }
};
