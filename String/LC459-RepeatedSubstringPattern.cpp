class Solution {
public:
    bool kmp(const string& query, const string& pattern) {
        int n = query.size();
        int m = pattern.size();
        vector<int> lps(m, -1);
        
        // preprocess lps in kmp
        for (int i = 1; i < m; ++i) {
            int j = lps[i - 1];
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = lps[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                lps[i] = j + 1;
            }
        }
        
        // find match
        int match = -1;
        for (int i = 1; i < n - 1; ++i) {
            while (match != -1 && pattern[match + 1] != query[i]) {
                match = lps[match];
            }
            if (pattern[match + 1] == query[i]) {
                match++;
                if (match == m - 1) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool repeatedSubstringPattern(string s) {
        return kmp(s + s, s);
    }
};
