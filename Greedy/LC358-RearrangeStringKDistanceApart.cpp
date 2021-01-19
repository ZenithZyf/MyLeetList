class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        string res;
        int len = (int)s.size();
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        for (auto a : s) {
            m[a]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            q.push({it->second, it->first});
        }
        while (!q.empty()) {
            vector<pair<int, char>> tmp;
            int cnt = min(len, k);
            for (int i = 0; i < cnt; i++) {
                if (q.empty()) return "";
                auto t = q.top(); q.pop();
                res.push_back(t.second);
                t.first -= 1;
                if (t.first > 0)
                    tmp.push_back(t);
                len--;
            }
            for (auto it : tmp) {
                q.push(it);
            }
        }
        return res;
    }
};
