class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 0) return true;
        bool increasing = true;
        bool decreasing = true;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1])
                increasing = false;
            if (A[i] < A[i + 1])
                decreasing = false;
        }
        return increasing || decreasing;
    }
};
