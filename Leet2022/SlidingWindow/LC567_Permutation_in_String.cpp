class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window, need;
        for (char c : s1) {
            ++need[c];
        }
        int left = 0, right = 0;
        int valid = 0;
        
        while (right <= s2.length()) {
            char c = s2[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) {
                    ++valid;
                }
            }
            if (valid == need.size()) {
                return true;
            }
            while (right - left >= s1.length()) {
                char d = s2[left];
                ++left;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        --valid;
                    }
                    --window[d];
                }
            }
        }
        
        return false;
        
    }
};
