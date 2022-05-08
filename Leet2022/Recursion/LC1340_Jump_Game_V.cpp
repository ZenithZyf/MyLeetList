class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        const int n = arr.size();
        vector<int> m(n);
        
        function<int(int)> dp = [&](int i) {
            if (m[i]) {
                return m[i];
            }
            int ans = 1;
            for (int j = i + 1; j <= min(n - 1, i + d) && arr[i] > arr[j]; ++j) {
                ans = std::max(ans, dp(j) + 1);
            }
            for (int j = i - 1; j >= max(0, i - d) && arr[i] > arr[j]; --j) {
                ans = std::max(ans, dp(j) + 1);
            }
            return m[i] = ans;
        };
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, dp(i));
        }
        return ans;
    }
};
