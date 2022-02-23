class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> graph(26, vector<bool>(26));
        vector<bool> visited(26);
        string res;
        for (string word : words) {
            for (char c : word) {
                graph[c - 'a'][c - 'a'] = true;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            int mlen = min(words[i].size(), words[i + 1].size());
            int j = 0;
            for (; j < mlen; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    graph[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
                    break;
                }
            }
            if (j == mlen && words[i].size() > words[i + 1].size()) {
                return "";
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (!dfs(graph, i, visited, res)) {
                return "";
            }
        }
        return res;
    }
private:
    bool dfs(vector<vector<bool>>& graph, int idx, vector<bool>& visited, string& res) {
        if (!graph[idx][idx]) {
            return true;
        }
        visited[idx] = true;
        for (int i = 0; i < 26; ++i) {
            if (i == idx || !graph[i][idx]) {
                continue;
            }
            if (visited[i]) {
                return false;
            }
            if (!dfs(graph, i, visited, res)) {
                return false;
            }
        }
        visited[idx] = false;
        graph[idx][idx] = false;
        res += 'a' + idx;
        return true;
    }
};
