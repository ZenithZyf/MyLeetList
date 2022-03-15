class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        const int n = heights.size();
        if (n == 0) {
            return {};
        }
        vector<int> ans;
        int height = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (heights[i] > height) {
                height = heights[i];
                ans.emplace_back(i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
