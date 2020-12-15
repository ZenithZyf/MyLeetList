class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> after(numCourses);
        vector<int> indegree(numCourses);
        
        for (auto pre : prerequisites) {
            after[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                que.push(i);
        }
        
        vector<int> res;
        while (!que.empty()) {
            int next = que.front(); que.pop();
            res.push_back(next);
            for (int c : after[next]) {
                indegree[c]--;
                if (indegree[c] == 0)
                    que.push(c);
            }
        }
        
        if (res.size() != numCourses)
            return {};
        return res;
    }
};
