class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0) + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int d = 1;
            int t = 0;
            for (int w : weights) {
                if ((t += w) > m) {
                    t = w;
                    d++;
                }
            }
            if (d <= D)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
