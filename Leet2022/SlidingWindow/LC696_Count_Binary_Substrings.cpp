class Solution {
public:
    int countBinarySubstrings(string s) {
        int scan = 0;
        int mark = 0;
        int ans = 0;
        vector<int> lens(2, 0);
        while (true) {
            while (scan < s.length() && s[scan] == s[mark]) {
                ++scan;
            }
            lens[s[mark] - '0'] = scan - mark;
            ans += min(lens[0], lens[1]);
            if (scan == s.length()) {
                break;
            }
            lens[s[scan] - '0'] = 0;
            mark = scan;
        }
        return ans;
    }
};
