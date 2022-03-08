class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> left;
        for (char c : s) {
            if (pairs.count(c)) {
                if (left.empty() || pairs[c] != left.top()) {
                    return false;
                }
                left.pop();
            } else {
                left.push(c);
            }
        }
        return left.empty();
    }
};
