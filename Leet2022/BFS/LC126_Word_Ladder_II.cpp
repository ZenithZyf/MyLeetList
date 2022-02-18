class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return {};
        }
        vector<vector<string>> ans;
        int len = beginWord.length();
        unordered_set<string> begin_set{beginWord};
        unordered_set<string> end_set{endWord};
        unordered_map<string, vector<string>> children;
        bool found = false;
        bool backward = false;
        
        while (!begin_set.empty() && !end_set.empty() &&!found) {
            if (begin_set.size() > end_set.size()) {
                std::swap(begin_set, end_set);
                backward = !backward;
            }
            for (const string& word : begin_set) {
                dict.erase(word);
            }
            for (const string& word : end_set) {
                dict.erase(word);
            }
            unordered_set<string> cur_set;
            for (const string& word : begin_set) {
                string cur = word;
                for (int i = 0; i < len; ++i) {
                    char c = cur[i];
                    for (int j = 'a'; j <= 'z'; ++j) {
                        cur[i] = j;
                        const string* parent = &word;
                        const string* child = &cur;
                        if (backward) {
                            std::swap(parent, child);
                        }
                        if (end_set.count(cur)) {
                            found = true;
                            children[*parent].emplace_back(*child);
                        } else if (dict.count(cur) && !found) {
                            cur_set.insert(cur);
                            children[*parent].emplace_back(*child);
                        }
                    }
                    cur[i] = c;
                }
            }
            std::swap(begin_set, cur_set);
        }
        
        if (found) {
            vector<string> path{beginWord};
            getPaths(beginWord, endWord, children, path, ans);
        }
        
        return ans;
    }
private:
    void getPaths(const string& word,
                  const string& endWord,
                  const unordered_map<string, vector<string>>& children,
                  vector<string>& path,
                  vector<vector<string>>& ans) {
        if (word == endWord) {
            ans.emplace_back(path);
            return;
        }
        
        const auto it = children.find(word);
        if (it == children.cend()) {
            return;
        }
        for (const string& child : it->second) {
            path.emplace_back(child);
            getPaths(child, endWord, children, path, ans);
            path.pop_back();
        }
    }
};
