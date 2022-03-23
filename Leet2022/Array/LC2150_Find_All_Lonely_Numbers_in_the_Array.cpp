class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            ++map[n];
        }
        vector<int> ans;
        for (auto m : map) {
            if (m.second == 1 && !map.count(m.first - 1) && !map.count(m.first + 1)) {
                ans.emplace_back(m.first);
            }
        }
        return ans;
    }
};
