class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        n_ = nums.size();
        vector<long> minTimes = getCnt(nums, true);
        vector<long> maxTimes = getCnt(nums, false);
        long long ans = 0;
        for (int i = 0; i < n_; ++i) {
            ans += (maxTimes[i] - minTimes[i]) * nums[i];
        }
        return ans;
    }
private:
    int n_;
    vector<long> getCnt(const vector<int>& nums, const bool isMin) {
        vector<int> a(n_);
        vector<int> b(n_);
        stack<int> d;
        for (int i = 0; i < n_; ++i) {
            while (!d.empty() && (isMin ? nums[d.top()] >= nums[i] : nums[d.top()] <= nums[i])) {
                d.pop();
            }
            a[i] = d.empty() ? -1 : d.top();
            d.push(i);
        }
        stack<int> e;
        for (int i = n_ - 1; i >= 0; --i) {
            while (!e.empty() && (isMin ? nums[e.top()] > nums[i] : nums[e.top()] < nums[i])) {
                e.pop();
            }
            b[i] = e.empty() ? n_ : e.top();
            e.push(i);
        }
        vector<long> ans(n_);
        for (int i = 0; i < n_; ++i) {
            ans[i] = static_cast<long>((i - a[i]) * (b[i] - i));
        }
        return ans;
    }
};
