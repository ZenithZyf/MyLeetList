class Solution {
public:
    Solution(vector<int>& w) {
        wsum = w;
        for (int i = 1; i < w.size(); ++i) {
            wsum[i] += wsum[i - 1];
        }
    }
    
    int pickIndex() {
        int rnum = rand() % wsum.back() + 1;
        int l = 0;
        int r = wsum.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (wsum[mid] < rnum) {
                l = mid + 1;
            } else if (wsum[mid] >= rnum) {
                r = mid;
            }
        }
        return r;
    }
private:
    vector<int> wsum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
