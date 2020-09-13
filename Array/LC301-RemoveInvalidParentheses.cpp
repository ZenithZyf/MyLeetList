class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0;
        int r = 0;
        
        // Find out how many redundant parentheses we have
        for (const char ch : s) {
            l += (ch == '(');
            if (l == 0)
                r += (ch == ')');
            else
                l -= (ch == ')');
        }
        
        vector<string> ans;
        dfs(s, 0, l, r, ans);
        return ans;
    }
private:
    bool isValid(const string& s) {
        int count = 0;
        for (const char ch : s) {
            if (ch == '(') ++count;
            if (ch == ')') --count;
            if (count < 0) return false;
        }
        return count == 0;
    }
    
    void dfs(const string& s, int start, int l, int r, vector<string>& ans) {
        if (l == 0 && r == 0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;
            
            if (r > 0) {
                string cur = s;
                if (s[i] == ')') {
                    cur.erase(i, 1);
                    dfs(cur, i, l, r - 1, ans);
                }
            } else if (l > 0) {
                string cur = s;
                if (s[i] == '(') {
                    cur.erase(i, 1);
                    dfs(cur, i, l - 1, r, ans);
                }
            }
        }
    }
};
