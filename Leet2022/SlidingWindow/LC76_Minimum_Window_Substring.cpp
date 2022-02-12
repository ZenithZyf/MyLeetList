class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, need;
        for (char c : t) {
            need[c] += 1;
        }
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        int valid = 0;
        while (right < s.length()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) {
                    ++valid;
                }
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char c = s[left];
                ++left;
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        --valid;
                    }
                    --window[c];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
