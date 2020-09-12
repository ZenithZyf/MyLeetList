class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        if (n > 0) dfs(ans, cur, n, n);
        return ans;
    }
private:
    void dfs(vector<string>& ans, string& cur, int l, int r) {
        if (l + r == 0) {
            ans.push_back(cur);
            return;
        }
        
        if (r < l) return;
        if (l > 0) {
            dfs(ans, cur += '(', l - 1, r);
            cur.pop_back();
        }
        if (r > 0) {
            dfs(ans, cur += ')', l, r - 1);
            cur.pop_back();
        }
    }
};
