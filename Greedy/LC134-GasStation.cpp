class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int spare = 0;
        int min_spare = INT_MAX;
        int min_index = -1;
        
        for (int i = 0; i < n; ++i) {
            spare += gas[i] - cost[i];
            if (spare < min_spare) {
                min_spare = spare;
                min_index = i;
            }
        }
        
        return spare < 0 ? -1 : (min_index + 1) % n;
    }
};
