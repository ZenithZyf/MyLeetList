class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int len = s.length();
        if (s[len - 1] == '1') {
            return false;
        }
        s[0] = '2';
        int limit = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '2') {
                for (limit = max(limit, i + minJump); limit <= min(len - 1, i + maxJump); ++limit) {
                    if (s[limit] == '0') {
                        s[limit] = '2';
                    }
                }
                if (s[len - 1] == '2') {
                    return true;
                }
            }
        }
        return false;
    }
};
