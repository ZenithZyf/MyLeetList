class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int ans = -1;
        vector<int> t(4);
        
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) if (j != i)
                for (int k = 0; k < 4; ++k) if (k != i && k != j) {
                    int l = 6 - k - j - i;
                    
                    int hours = 10 * A[i] + A[j];
                    int mins = 10 * A[k] + A[l];
                    if (hours < 24 && mins < 60) {
                        if (hours * 60 + mins > ans) {
                            ans = hours * 60 + mins;
                            t = {A[i], A[j], A[k], A[l]};
                        }
                    }
                }
        
        return ans >= 0 ? to_string(t[0]) + to_string(t[1]) + ":" + to_string(t[2]) + to_string(t[3]) : "";
    }
};
