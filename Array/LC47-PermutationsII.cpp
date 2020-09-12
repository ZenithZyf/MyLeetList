class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(n);
        
        std::sort(begin(nums), end(nums));
        dfs(ans, path, used, nums);
        return ans;
        
    }
private:
    void dfs(vector<vector<int>>& ans, vector<int>& path, vector<int>& used, vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            dfs(ans, path, used, nums);
            path.pop_back();
            used[i] = 0;
        }
    }
};
