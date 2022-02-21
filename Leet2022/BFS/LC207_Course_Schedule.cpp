class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegrees(numCourses, 0);
        for (const vector<int> course : prerequisites) {
            graph[course[0]].emplace_back(course[1]);
            ++indegrees[course[1]];
        }
        queue<int> q_course;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q_course.push(i);
                visited[i] = 1;
            }
        }
        int taked = 0;
        while (!q_course.empty()) {
            int cur_course = q_course.front(); q_course.pop();
            ++taked;
            for (const int next_course : graph[cur_course]) {
                if (visited[next_course]) {
                    continue;
                }
                if (--indegrees[next_course] == 0) {
                    q_course.push(next_course);
                    visited[next_course] = 1;
                }
            }
        }
        return taked == numCourses ? true : false;
    }
};
