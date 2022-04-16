/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto e : employees) {
            es_.emplace(e->id, e);
        }
        
        queue<int> q;
        q.push(id);
        int sum = 0;
        while (!q.empty()) {
            int eid = q.front(); q.pop();
            auto e = es_[eid];
            sum += e->importance;
            for (auto sid : e->subordinates) {
                q.push(sid);
            }
        }
        return sum;
    }
private:
    unordered_map<int, Employee*> es_;
};
