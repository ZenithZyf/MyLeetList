class Solution {
public:
    int minSwaps(vector<int>& data) {
        const int n = data.size();
        int cnt = 0;
        for (int d : data) {
            if (d == 1) {
                ++cnt;
            }
        }
        if (cnt <= 1) {
            return 0;
        }
        int left = 0, right = cnt - 1;
        int ans = INT_MAX;
        int exist = 0;
        for (int i = left; i <= right; ++i) {
            if (data[i] == 1) {
                ++exist;
            }
        }
        ans = std::min(ans, cnt - exist);
        while (right < n) {
            if (data[left] == 1) {
                --exist;
            }
            ++left;
            ++right;
            if (right < n && data[right] == 1) {
                ++exist;
            }
            ans = std::min(ans, cnt - exist);
        }
        return ans;
    }
};
