class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string& s : words) {
            s_.insert(s);
        }
        vector<string> ans;
        for (string& s : words) {
            if (check(s)) {
                ans.push_back(s);
            }
        }
        return ans;
    }
private:
    unordered_set<string> s_;
    bool check(const string& s) {
        int n = s.length();
        vector<int> comb(n + 1, -1);
        comb[0] = 0;
        for (int i = 0; i <= n; ++i) {
            if (comb[i] == -1) {
                continue;
            }
            for (int j = i + 1; j <= n; ++j) {
                string cur = s.substr(i, j - i);
                if (s_.count(cur)) {
                    comb[j] = max(comb[j], comb[i] + 1);
                }
            }
            if (comb[n] > 1) {
                return true;
            }
        }
        return false;
    }
};
