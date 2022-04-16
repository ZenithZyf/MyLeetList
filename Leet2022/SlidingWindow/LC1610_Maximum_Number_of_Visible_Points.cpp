class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int at_origin = 0;
        vector<double> ps;
        for (const auto& p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                ++at_origin;
            } else {
                ps.push_back(atan2(p[1] - location[1], p[0] - location[0]));
            }
        }
        std::sort(ps.begin(), ps.end());
        const int n = ps.size();
        for (int i = 0; i < n; ++i) {
            ps.push_back(ps[i] + 2.0 * M_PI);
        }
        int l = 0;
        int ans = 0;
        double fov = angle * M_PI / 180.0;
        for (int r = 0; r < ps.size(); ++r) {
            while (ps[r] - ps[l] > fov) {
                ++l;
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans + at_origin;
    }
};
