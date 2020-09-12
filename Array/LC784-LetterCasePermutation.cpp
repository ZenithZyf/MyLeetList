class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(ans, 0, S);
        return ans;
    }
private:
    void dfs(vector<string>& ans, int s, string& S) {
        if (s == S.size()) {
            ans.push_back(S);
            return;
        }
        dfs(ans, s + 1, S);
        if (!isalpha(S[s])) return;
        S[s] ^= (1 << 5);
        dfs(ans, s + 1, S);
        S[s] ^= (1 << 5);
    }
};
