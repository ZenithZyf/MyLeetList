class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int n = words.size();
        std::sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (valid(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
private:
    bool valid(const string& a, const string& b) {
        if (a.length() + 1 != b.length()) {
            return false;
        }
        int cnt = 0;
        for (int i = 0, j = 0; i < a.length() && j < b.length();) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                ++cnt;
                ++j;
            }
        }
        return cnt <= 1;
    }
};
