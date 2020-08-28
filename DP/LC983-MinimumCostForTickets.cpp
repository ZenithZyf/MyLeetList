class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        int day = 0;
        for (int i = 1; i < days.back() + 1; ++i) {
            if (i != days[day]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = std::min({dp[max(0, i - 1)] + costs[0],
                                  dp[max(0, i - 7)] + costs[1],
                                  dp[max(0, i - 30)] + costs[2]});
                day += 1;
            }
        }
        return dp.back();
    }
};
