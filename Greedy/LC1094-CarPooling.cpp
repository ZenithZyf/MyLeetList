class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> capacityChange(1001, 0);
        for (int i = 0; i < trips.size(); ++i) {
            capacityChange[trips[i][1]] += trips[i][0];
            capacityChange[trips[i][2]] -= trips[i][0];
        }
        
        for (int i = 1; i < 1001; ++i) {
            capacity -= capacityChange[i];
            if (capacity < 0)
                return false;
        }
        
        return true;
        
    }
};
