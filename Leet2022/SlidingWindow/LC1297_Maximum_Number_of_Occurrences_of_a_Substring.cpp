class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0;
        const int n = s.length();
        unordered_map<string, int> m;
        for (int i = 0; i < n - minSize + 1; ++i) {
            string tmp = s.substr(i, minSize);
            set<char> tmp_set(tmp.cbegin(), tmp.cend());
            if (tmp_set.size() <= maxLetters) {
                ++m[tmp];
            }
        }
        for (auto it : m) {
            res = max(res, it.second);
        }
        return res;
    }
};
