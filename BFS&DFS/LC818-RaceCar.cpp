class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        q.push({0, 1});
        unordered_set<int> v;
        v.insert({0, 2});
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front(); q.pop();
                int pos = p.first;
                int speed = p.second;
                pair<int, int> p1 = {pos + speed, speed * 2};
                if (p1.first == target) return steps + 1;
                if (p1.first > 0 && p1.first < 2 * target && p1.second < 2 * target)
                    q.push(p1);
                int speed2 = speed > 0 ? -1 : 1;
                pair<int, int> p2 = {pos, speed2};
                int key = (pos << 2) | (speed2 + 1);
                if (!v.count(key) && p2.first >= target / 2) {
                    q.push(p2);
                    v.insert(key);
                }
            }
            ++steps;
        }
        
        return -1;
    }
};
