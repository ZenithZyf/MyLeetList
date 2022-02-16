class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0,  right = 0;
        int res = 0;
        while (right < s.length()) {
            char cur_right = s[right];
            ++right;
            ++window[cur_right];
            while (window[cur_right] > 1) {
                char cur_left = s[left];
                ++left;
                --window[cur_left];
            }
            res = max(res, right - left);
        }
        return res;
    }
};
