class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        int a = s.size();
        bool b = dp[8];
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!dp[i])
                continue;
            for (auto& word : wordDict) {
                if (word.size() + i <= s.size() && s.substr(i, word.size()) == word)
                    dp[i + word.size()] = true;
            }
        }
        return dp[s.size()];
    }
};
