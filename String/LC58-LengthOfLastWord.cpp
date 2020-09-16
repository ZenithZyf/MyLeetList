class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) return 0;
        int n = s.length();
        int cnt = 0;
        int flag = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (flag == 1) break;
                continue;
            } else {
                flag = 1;
                cnt++;
            }
        }
        return cnt;
    }
};
