class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {   
        if (amount == 0) return 0;
        
        vector<int> visited(amount + 1, -2);
        queue<int> next;
        
        for (auto coin : coins) {
            if (amount - coin >= 0) {
                visited[amount - coin] = 1;
                next.push(amount - coin);
            }
        }
        
        int cnt = 1;
        while (!next.empty()) {
            int n = next.size();
            for (int i = 0; i < n; ++i) {
                int visiting = next.front();
                next.pop();
                if (visiting == 0)
                    return cnt;
                for (auto coin : coins) {
                    if (visiting - coin >= 0) {
                        if (visited[visiting - coin] != 1) {
                            next.push(visiting - coin);
                            visited[visiting - coin] = 1;
                        }
                    }
                }
            }
            cnt++;
        }
        
        return -1;
    }
};
