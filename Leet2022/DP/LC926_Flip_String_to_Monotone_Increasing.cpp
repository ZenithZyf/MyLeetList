class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int n = s.size();
        int dp0 = 0;
        int dp1 = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp0 = dp0 + (s[i - 1] == '1');
            dp1 = min(dp0, dp1) + (s[i - 1] == '0');
            dp0 = tmp0;
        }
        return min(dp0, dp1);
    }
};
