class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1) {
            return "";
        }
        string res;
        for (int i = 0; i < s.length(); ++i) {
            string sub_str1 = validPalindrome(i, i, s);
            string sub_str2 = validPalindrome(i, i + 1, s);
            string temp = sub_str1.size() > sub_str2.size() ? sub_str1 : sub_str2;
            res = res.size() > temp.size() ? res : temp;
        }
        return res;
    }
private:
    string validPalindrome(int i, int j, const string& s) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return s.substr(i + 1, j - i - 1);
    }
};
