class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        
        int curDiff = A[1] - A[0];
        int cnt = 2;
        int total = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == curDiff) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    total += (cnt - 3 + 1) * (cnt - 3 + 2) / 2;
                }
                cnt = 2;
                curDiff = A[i] - A[i - 1];
            }
        }
        
        if (cnt >= 3) {
            total += (cnt - 3 + 1) * (cnt - 3 + 2) / 2;
        }
        
        return total;
    }
};
