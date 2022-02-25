class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> roots(n, -1);
        for (auto& e : edges) {
            int x = find(roots, e[0]);
            int y = find(roots, e[1]);
            if (x == y) {
                return false;
            }
            roots[x] = y;
        }
        return true;
    }
private:
    int find(vector<int>& roots, int i) {
        while (roots[i] != -1) {
            i = roots[i];
        }
        return i;
    }
};
