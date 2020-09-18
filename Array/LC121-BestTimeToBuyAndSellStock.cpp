class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = INT_MAX;
        int cur_pro = 0;
        for (int i = 0; i < prices.size(); ++i) {
            cur_min = std::min(cur_min, prices[i]);
            cur_pro = std::max(cur_pro, prices[i] - cur_min);
        }
        return cur_pro;
    }
};
