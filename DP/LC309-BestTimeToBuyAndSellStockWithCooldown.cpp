class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN;
        int sold = 0;
        int rest = 0;
        for (const int p : prices) {
            int prev_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prev_sold);
        }
        return max(rest, sold);
    }
};
