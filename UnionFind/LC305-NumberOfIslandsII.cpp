class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        int cnt = 0;
        vector<int> roots(m * n, -1);
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto& pos : positions) {
            int id = n * pos[0] + pos[1];
            if (roots[id] != -1) {
                res.push_back(cnt);
                continue;
            }
            roots[id] = id;
            ++cnt;
            for (auto dir : dirs) {
                int x = pos[0] + dir[0];
                int y = pos[1] + dir[1];
                int cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1)
                    continue;
                int p = findRoot(roots, cur_id);
                int q = findRoot(roots, id);
                if (p != q) {
                    roots[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
private:
    int findRoot(vector<int>& roots, int id) {
        return (id == roots[id]) ? id : findRoot(roots, roots[id]);
    }
};
