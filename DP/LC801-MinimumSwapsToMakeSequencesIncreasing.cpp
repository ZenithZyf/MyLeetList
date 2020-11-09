class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        
        long keep1 = 0;
        long swap1 = 1;
        
        for (int i = 1; i < n; ++i) {
            long keep2 = INT_MAX;
            long swap2 = INT_MAX;
            
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep2 = keep1;
                swap2 = swap1 + 1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                swap2 = min(swap2, keep1 + 1);
                keep2 = min(keep2, swap1);
            }
            
            keep1 = keep2;
            swap1 = swap2;
        }
        
        return min(keep1, swap1);
    }
};
