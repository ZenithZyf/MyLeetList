class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m_ = forest.size();
        n_ = forest[0].size();
        
        vector<tuple<int, int, int>> trees;
        for (int y = 0; y < m_; ++y)
            for (int x = 0; x < n_; ++x)
                if (forest[y][x] > 1)
                    trees.emplace_back(forest[y][x], x, y);
        
        sort(trees.begin(), trees.end());
        
        int sx = 0;
        int sy = 0;
        int total_steps = 0;
        
        for (int i = 0; i < trees.size(); ++i) {
            int tx = get<1>(trees[i]);
            int ty = get<2>(trees[i]);
            
            int steps = bfs(forest, sx, sy, tx, ty);
            if (steps == INT_MAX) return -1;
            
            forest[ty][tx] = 1;
            
            total_steps += steps;
            
            sx = tx;
            sy = ty;
        }
        
        return total_steps;
    }
private:
    int m_;
    int n_;
    
    int bfs(const vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        vector<int> dirs = {0, -1, 0, 1, 0};
        vector<vector<int>> visited(m_, vector<int>(n_, 0));
        
        queue<pair<int, int>> q;
        q.push({sx, sy});
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front(); q.pop();
                const int nx = node.first;
                const int ny = node.second;
                
                if (nx == tx && ny == ty)
                    return steps;
                
                for (int i = 0; i < 4; ++i) {
                    const int x = nx + dirs[i];
                    const int y = ny + dirs[i + 1];
                    if (x < 0 || x == n_ || y < 0 || y == m_ 
                        || !forest[y][x] || visited[y][x])
                        continue;
                    
                    visited[y][x] = 1;
                    q.push({x, y});
                }
            }
            ++steps;
        }
        
        return INT_MAX;
    }
};
