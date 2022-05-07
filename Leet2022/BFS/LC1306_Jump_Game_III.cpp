class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        vector<int> seen(n);
        seen[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (arr[cur] == 0) {
                return true;
            }
            for (int i : {-1, 1}) {
                int t = cur + i * arr[cur];
                if (t < 0 || t >= n || seen[t]) {
                    continue;
                }
                q.push(t);
                seen[t] = 1;
            }
        }
        return false;
    }
};
