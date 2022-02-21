class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (const vector<int> course : prerequisites) {
            graph[course[1]].emplace_back(course[0]);
            ++indegrees[course[0]];
        }
        queue<int> q_course;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q_course.push(i);
            }
        }
        vector<int> res;
        while (!q_course.empty()) {
            int cur_course = q_course.front(); q_course.pop();
            res.emplace_back(cur_course);
            for (const int next_course : graph[cur_course]) {
                if (--indegrees[next_course] == 0) {
                    q_course.push(next_course);
                }
            }
        }
        if (res.size() != numCourses) {
            return {};
        }
        return res;
    }
};
