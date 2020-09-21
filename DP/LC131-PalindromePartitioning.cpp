class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<vector<string>>> dp(n + 1);
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < l; ++i) {
                string right = s.substr(i, l - i);
                if (!isValid(right)) continue;
                if (i == 0) dp[l].push_back({right});
                for (const auto& p : dp[i]) {
                    dp[l].push_back(p);
                    dp[l].back().push_back(right);
                }
            }
        }
        return dp[n];
    }
private:
    bool isValid(const string& s) {
        const int n = s.length();
        for (int i = 0; i < n; ++i)
            if (s[i] != s[n - 1 - i])
                return false;
        return true;
    }
};
