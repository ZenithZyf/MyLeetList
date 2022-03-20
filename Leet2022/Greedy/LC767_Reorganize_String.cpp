class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        string res;
        for (char c : s) {
            ++m[c];
        }
        for (auto [c, i] : m) {
            pq.emplace(i, c);
        }
        pair<int, char> last = {-1, 0};
        while (!pq.empty()) {
            auto [i, c] = pq.top(); pq.pop();
            res += c;
            if (last.first > 0) {
                pq.push(last);
            }
            last = {i - 1, c};
        }
        return last.first > 0 ? "" : res;
    }
};
