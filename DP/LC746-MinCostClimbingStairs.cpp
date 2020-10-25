class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp0 = 0;
        int dp1 = 0;
        int ans = 0;
        for (int i = 2; i <= cost.size(); i++) {
            ans = std::min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
            int tmp = dp1;
            dp1 = ans;
            dp0 = tmp;
        }
        
        return ans;
    }
};
