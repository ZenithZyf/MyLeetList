class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        constexpr int kMod = 1e9 + 7;
        vector<int> minTimes = getCnt(arr);
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            res = (res + static_cast<long>(minTimes[i]) * arr[i]) % kMod;
        }
        return res;
    }
private:
    vector<int> getCnt(const vector<int>& arr) {
        const int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> d;
        for (int i = 0; i < n; ++i) {
            while (!d.empty() && (arr[i] <= arr[d.top()])) {
                d.pop();
            }
            left[i] = d.empty() ? -1 : d.top();
            d.push(i);
        }
        stack<int> e;
        for (int i = n - 1; i >= 0; --i) {
            while (!e.empty() && (arr[i] < arr[e.top()])) {
                e.pop();
            }
            right[i] = e.empty() ? n : e.top(); 
            e.push(i);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (i - left[i]) * (right[i] - i);
        }
        return ans;
    }
};
