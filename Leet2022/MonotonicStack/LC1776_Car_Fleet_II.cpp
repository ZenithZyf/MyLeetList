class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size());
        stack<int> s;
        for (int i = cars.size() - 1; i>= 0; --i) {
            while (s.size()) {
                if (cars[s.top()][1] >= cars[i][1]) {
                    s.pop();
                } else {
                    if (ans[s.top()] < 0) {
                        break;
                    }
                    double d = ans[s.top()] * (cars[i][1] - cars[s.top()][1]);
                    if (d > cars[s.top()][0] - cars[i][0]) {
                        break;
                    } else {
                        s.pop();
                    }
                }
            }
            if (s.empty()) {
                ans[i] = -1;
            } else {
                double t = double(cars[s.top()][0] - cars[i][0]) / double(cars[i][1] - cars[s.top()][1]);
                ans[i] = t;
            }
            s.push(i);
        }
        return ans;
    }
};
