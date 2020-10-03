class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        
        int ans = 0;
        int j = 0;
        for (int i = 0; i < g.size(); ++i) {
            while (j < s.size() && s[j] < g[i])
                ++j;
            if (j < s.size()) {
                ++ans;
                ++j;
                continue;
            }
        }
        return ans;
    }
};
