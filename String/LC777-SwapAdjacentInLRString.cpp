class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int n1 = end.size();
        int s = -1;
        int e = -1;
        while (e++ < n1 && s++ < n1) {
            while (e < n1 && end[e] == 'X') {
                e++;
            }
            while (s < n1 && start[s] == 'X') {
                s++;
            }
            if ((e < n1) ^ (s < n1))
                return false;
            if (start[s] != end[e] || (start[s] == 'L' && s < e) || (start[s] == 'R' && s > e)) {
                return false;
            }
        }
        return true;
    }
};
