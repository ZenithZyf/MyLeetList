class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        for (char c : p) {
            ++need[c];
        }
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        
        while (right <= s.length()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) {
                    ++valid;
                }
            }
            if (valid == need.size()) {
                res.emplace_back(left);
            }
            while (right - left >= p.length()) {
                char d = s[left];
                ++left;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        --valid;
                    }
                    --window[d];
                }
            }
        }
        
        return res;
        
    }
};
