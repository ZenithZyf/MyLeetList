class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> ans;
        
        for (const auto& v : synonyms) {
            fa[v[0]] = v[0];
            fa[v[1]] = v[1];
        }
        
        for (const auto& v : synonyms) {
            candidates.insert(v[0]);
            candidates.insert(v[1]);
            if (find(v[0]) != find(v[1])) {
                fa[find(v[0])] = find(v[1]);
            }
        }
        
        solve(0, text, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    unordered_set<string> candidates;
    unordered_map<string, string> fa;
    
    string find(string x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    
    void solve(int idx, string& text, vector<string>& ans) {
        if (idx > text.length()) {
            ans.push_back(text);
            return;
        }
        
        string word;
        int i;
        for (i = idx; i < text.size() && text[i] != ' '; ++i) {
            word += text[i];
        }
        ++i;
        solve(i, text, ans);
        
        string tmp = text;
        if (fa.find(word) != fa.end()) {
            for (const string& s : candidates) {
                if (word != s && find(word) == find(s)) {
                    text.replace(idx, word.length(), s);
                    solve(i - word.size() + s.size(), text, ans);
                    text = tmp;
                }
            }
        }
    }
};
