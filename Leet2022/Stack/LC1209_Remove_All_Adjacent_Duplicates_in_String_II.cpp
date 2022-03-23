class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk{{'*', 0}};
        for (auto c : s) {
            if (c != stk.back().first) {
                stk.push_back({c, 1});
            } else if (++stk.back().second == k) {
                stk.pop_back();
            }
        }
        string res;
        for (auto p : stk) {
            res += string(p.second, p.first);
        }
        return res;
    }
};
