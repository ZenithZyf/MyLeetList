class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        const int n = log2(N);
        const int mask = (1 << n) - 1;
        return (~N) & mask;
    }
};
