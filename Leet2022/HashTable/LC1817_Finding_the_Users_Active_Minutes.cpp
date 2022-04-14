class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        for (auto& log : logs) {
            m_[log[0]].insert(log[1]);
        }
        vector<int> ans(k);
        for (auto& mi : m_) {
            ++ans[mi.second.size() - 1];
        }
        return ans;
    }
private:
    unordered_map<int, unordered_set<int>> m_; // id -> processing time
};
