class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int res = 0;
        int sign = 1;
        int num = 0;
        int curRes = 0;
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= '0') {
                num = num * 10 + (c - '0');
                // res += sign * num;
            } else if (c == '(') {
                int j = i;
                int cnt = 0;
                for (; i < n; i++) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch(op) {
                    case '+' : curRes += num; break;
                    case '-' : curRes -= num; break;
                    case '*' : curRes *= num; break;
                    case '/' : curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
        
    }
};
