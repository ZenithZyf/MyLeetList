class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int curMin = INT_MAX;
        int curMax = INT_MIN;
        int cnt = 0;
        
        while (right < n) {
            curMin = std::min(curMin, arr[right]);
            curMax = std::max(curMax, arr[right]);
            if (curMin == left && curMax == right) {
                cnt++;
                left = ++right;
                curMin = INT_MAX;
                curMax = INT_MIN;
            } else {
                right++;
            }
        }
        return cnt;
    }
};
