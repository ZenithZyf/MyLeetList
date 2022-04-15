class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        int cur = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = cur;
        for (int i = 0; i < k; ++i) {
            cur = cur - cardPoints[k - i - 1] + cardPoints[n - i - 1];
            ans = max(cur, ans);
        }
        return ans;
    }
};
