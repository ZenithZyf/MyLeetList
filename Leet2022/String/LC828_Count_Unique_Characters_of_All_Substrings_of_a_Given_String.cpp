class Solution {
public:
    int uniqueLetterString(string s) {
        int len = s.length();
        vector<int> left(len, -1);
        vector<int> right(len, -1);
        
        vector<int> prev(26, -1);
        for (int i = 0; i < len; ++i) {
            left[i] = prev[s[i] - 'A'];
            prev[s[i] - 'A'] = i;
        }
        
        for (int i = 0; i < 26; ++i) {
            prev[i] = len;
        }
        
        for (int i = len - 1; i >= 0; --i) {
            right[i] = prev[s[i] - 'A'];
            prev[s[i] - 'A'] = i;
        }
        
        long long int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = (ans + (i - left[i]) * (right[i] - i)) % 1000000007;
        }
        
        return ans;
    }
};
