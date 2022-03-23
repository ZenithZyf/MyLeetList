class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n == 0) {
            return 0;
        }
        int l = 0;
        int r = n - 1;
        int maxL = height[0];
        int maxR = height[n - 1];
        int ans = 0;
        while (l < r) {
            if (maxL < maxR) {
                ans += maxL - height[l];
                maxL = std::max(maxL, height[++l]);
            } else {
                ans += maxR - height[r];
                maxR = std::max(maxR, height[--r]);
            }
        }
        return ans;
    }
};
