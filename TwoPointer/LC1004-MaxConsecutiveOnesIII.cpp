class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int r = 0;
        int max_len = 0;
        int cnt = 0;
        
        while (r < A.size()) {
            if (A[r] == 0)
                cnt++;
            while (cnt > K) {
                if (A[l++] == 0)
                    cnt--;
            }
            max_len = std::max(max_len, r - l + 1);
            r++;
        }
        
        return max_len;
    }
};
