class Solution {
public:
    int mySqrt(int x) {
        constexpr double epsilon = 1e-2;
        double x0 = x;
        while (x0 * x0 - x > epsilon) {
            x0 = (x0 + x / x0) / 2.0;
        }
        return x0;
    }
};
