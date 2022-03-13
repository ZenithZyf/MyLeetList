class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 0;
        for (i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                --k;
            }
            if (!k) {
                return i;
            }
        }
        --i;
        if (i * i == n) {
            --i;
        }
        for (; i > 0; --i) {
            if (n % i == 0) {
                --k;
            }
            if (!k) {
                return n / i;
            }
        }
        return -1;
    }
};
