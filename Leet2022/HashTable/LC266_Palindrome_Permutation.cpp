class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> meet;
        for (const char c : s) {
            ++meet[c];
        }
        bool flag = false;
        for (auto m : meet) {
            if (m.second % 2 == 1) {
                if (flag == true) {
                    return false;
                }
                flag = true;
            }
        }
        return true;
    }
};
