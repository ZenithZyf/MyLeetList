class Solution {
public:
    void adjustHeap(vector<int>& hp, int idx, function<bool(const int& a, const int& b)> cmp) {
        for (int i = idx; i * 2 + 1 < hp.size();) {
            int t = i * 2 + 1;
            t += (t + 1 < hp.size() && !cmp(hp[t + 1], hp[t]));
            if (!cmp(hp[i], hp[t])) break;
            swap(hp[i], hp[t]);
            i = t;
        }
    }

    void buildHeap(vector<int>& hp, function<bool(const int& a, const int& b)> cmp) {
        for (int i = hp.size() / 2 - 1; i >= 0; i--) {
            adjustHeap(hp, i, cmp);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> ans(nums.begin(), nums.begin() + k);
        auto cmp = [](const int& a, const int& b) { return a > b; };
        buildHeap(ans, cmp);
        for (int i = k; i < nums.size(); i++) {
            if (!cmp(nums[i], ans[0])) continue;
            ans[0] = nums[i];
            adjustHeap(ans, 0, cmp);
        }
        return ans[0];
    }
};
