class Solution {
public:
    int minAddToMakeValid(string s) {
        int need = 0;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++need;
            }
            if (s[i] == ')') {
                --need;
                if (need == -1) {
                    ++res;
                    need = 0;
                }
            }
        }
        return res + need;
    }
};
