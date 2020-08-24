class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        
        unordered_set<string> visited;
        visited.insert(start);
        
        int mutations = 0;
        while (!q.empty()) {
            size_t n = q.size();
            while (n--) {
                string cur = std::move(q.front()); q.pop();
                if (cur == end) return mutations;
                for (const string& gene : bank) {
                    if (visited.count(gene) || !validMutation(cur, gene)) continue;
                    visited.insert(gene);
                    q.push(gene);
                }
            }
            ++mutations;
        }
        return -1;
    }
private:
    bool validMutation(const string& s1, const string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i)
            if (s1[i] != s2[i] && cnt++) return false;
        return true;
    }
};
