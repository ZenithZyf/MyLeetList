class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cnt;
        int l = 0;
        int r = 0;
        int res = 0;
        while (r < s.length()) {
            if (cnt.count(s[r])) {
                cnt.erase(s[l]);
                l++;
            } else {
                cnt.insert(s[r]);
                res = max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};
