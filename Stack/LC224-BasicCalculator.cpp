class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int n = s.size();
        int sign = 1;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= '0') {
                int nums = 0;
                while (i < n && s[i] >= '0') {
                    nums = nums * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                res += sign * nums;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};
