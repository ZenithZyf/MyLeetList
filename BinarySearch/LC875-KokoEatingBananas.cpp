class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));
        while (l < r) {
            int m = l + (r - l) / 2;
            int h = 0;
            for (int p : piles)
                h += (p - 1) / m + 1;
            if (h <= H)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
