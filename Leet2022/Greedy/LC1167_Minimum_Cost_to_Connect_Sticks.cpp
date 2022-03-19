class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int s : sticks) {
            pq.push(s);
        }
        int res = 0;
        while (pq.size() > 1) {
            int tmp = pq.top(); pq.pop();
            tmp += pq.top(); pq.pop();
            res += tmp;
            pq.push(tmp);
        }
        return res;
    }
};
