class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(n);
        
        function<void(int)> dfs = [&](int d) {
            if (d == n) {
                ans.emplace_back(path);
                return;
            }
            
            for (int i = 0; i < n; ++i) {
                if (used[i] == 1) continue;
                used[i] = 1;
                path.emplace_back(nums[i]);
                dfs(d + 1);
                path.pop_back();
                used[i] = 0;
            }
        };
        
        dfs(0);
        return ans;
    }
};
