class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, 0, target, cur);
        return ans;
    }
private:
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int s, int target, vector<int>& cur) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = s; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) return;
            if (i > s && candidates[i] == candidates[i - 1]) continue;
            cur.push_back(candidates[i]);
            dfs(ans, candidates, i + 1, target - num, cur);
            cur.pop_back();
        }
    }
};
