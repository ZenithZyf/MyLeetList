/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int cur = read4(buf + ans);
            if (cur == 0) break;
            ans += cur;
        }
        return std::min(ans, n);
    }
};
