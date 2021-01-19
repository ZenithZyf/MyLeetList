class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> mp;
        for (string s : strings) {
            string t;
            for (char c : s) {
                t += to_string((c + 26 - s[0]) % 26) + ',';
            }
            mp[t].insert(s);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};
