class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int prev_min = INT_MAX;
        int ans = 0;
        for (int p : prices) {
            if (p < prev_min) {
                prev_min = p;
                continue;
            }
            ans = std::max(ans, p - prev_min);
        }
        return ans;
    }
};
