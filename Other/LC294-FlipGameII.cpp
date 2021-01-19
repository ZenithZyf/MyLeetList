class Solution {
public:
    bool canWin(string s) {
        int n = s.length();
        if (n <= 1) return false;
        for (int i = 1; i < n; i++) {
            if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1)))
                return true;
        }
        return false;
    }
};
