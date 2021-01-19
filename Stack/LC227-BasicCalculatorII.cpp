class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < n && s[i] >= '0') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if (sign == 1) {
                    st.push(num);
                } else if (sign == 2) {
                    st.push(0 - num);
                } else if (sign == 3) {
                    int tmp = st.top(); st.pop();
                    st.push(tmp * num);
                } else if (sign == 4) {
                    int tmp = st.top(); st.pop();
                    st.push(tmp / num);
                }
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = 2;
            } else if (c == '*') {
                sign = 3;
            } else if (c == '/') {
                sign = 4;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top(); st.pop();
        }
        return res;
    }
};
