class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            vector<int> cnt(26);
            string t;
            for (char c : str) cnt[c- 'a']++;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                t += string(1, i + 'a') + to_string(cnt[i]);
            }
            mp[t].push_back(str);
        }
        for (auto m : mp) {
            res.push_back(m.second);
        }
        return res;
    }
};
