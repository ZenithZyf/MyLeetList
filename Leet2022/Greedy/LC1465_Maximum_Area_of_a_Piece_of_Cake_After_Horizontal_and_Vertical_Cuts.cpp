class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        constexpr int kMod = 1e9 + 7;
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        int max_row = std::max(horizontalCuts[0], h - horizontalCuts.back());
        int max_col = std::max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            max_row = max(max_row, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            max_col = max(max_col, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return static_cast<long>(max_row) * max_col % kMod;
    }
};
