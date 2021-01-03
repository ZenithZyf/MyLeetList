class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        int ans = 1;
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        vector<int> count(26);
        
        for (int i = 0; i < n; i++) {
            count[text[i] - 'a']++;
        }
        
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (text[i] == text[i - 1]) {
                c++;
            } else {
                c = 1;
            }
            left[i] = c;
        }
        
        c = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (text[i] == text[i + 1]) {
                c++;
            } else {
                c = 1;
            }
            right[i] = c;
        }
        
        for (int i = 1; i < n - 1; i++) {
            if (count[text[i - 1] - 'a'] > left[i - 1]) {
                ans = max(ans, left[i - 1] + 1);
            }
            if (count[text[i + 1] - 'a'] > right[i + 1]) {
                ans = max(ans, right[i + 1] + 1);
            }
            if (text[i - 1] == text[i + 1]) {
                if (count[text[i - 1] - 'a'] > left[i - 1] + right[i + 1]) {
                    ans = max(ans, left[i - 1] + right[i + 1] + 1);
                } else {
                    ans = max(ans, left[i - 1] + right[i + 1]);
                }
            }
        }
        
        return ans;
    }
};
