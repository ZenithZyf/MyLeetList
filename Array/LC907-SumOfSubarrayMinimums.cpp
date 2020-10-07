class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        constexpr int kMod = 1e9 + 7;
        const int n = A.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<pair<int, int>> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (!s.empty() && s.top().first > A[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(A[i], len);
            left[i] = len;
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; --i) {
            int len = 1;
            while (!s.empty() && s.top().first >= A[i]) {
                len += s.top().second;
                s.pop();
            }
            s.emplace(A[i], len);
            right[i] = len;
        }
        for (int i = 0;  i < n; ++i)
            ans = (ans + static_cast<long>(left[i]) * A[i] * right[i]) % kMod;
        
        return ans;
    }
};
