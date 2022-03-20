class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> c;
        for (int x : arr) {
            ++c[x];
        }
        vector<int> m;
        for (const auto [x, f] : c) {
            m.push_back(f);
        }
        std::sort(m.begin(), m.end());
        int ans = m.size();
        int i = 0;
        while (k--) {
            if (--m[i] == 0) {
                ++i;
                --ans;
            }
        }
        return ans;
    }
};
