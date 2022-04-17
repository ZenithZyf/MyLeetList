class Solution {
public:
    string minWindow(string s1, string s2) {
        const int m = s1.size(), n = s2.size();
        int start = -1, minLen = INT_MAX, i = 0, j = 0;
        while (i < m) {
            if (s1[i] == s2[j]) {
                if (++j == n) {
                    int end = i + 1;
                    while (--j >= 0) {
                        while (s1[i--] != s2[j]);
                    }
                    ++i; ++j;
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }
        return (start != -1) ? s1.substr(start, minLen) : "";
    }
};
