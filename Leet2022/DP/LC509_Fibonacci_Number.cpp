class Solution {
public:
    int fib(int n) {
        if (n == 1 || n == 0) {
            return n;
        }
        int prev = 0, curr = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = prev + curr;
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};
