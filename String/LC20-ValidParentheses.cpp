class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> pairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> left;
        
        for (const char ch : s) {
            if (pairs.count(ch)) {
                if (left.empty() || pairs[ch] != left.top())
                    return false;
                left.pop();
            } else {
                left.push(ch);
            }
        }
        
        return left.empty();
    }
};
