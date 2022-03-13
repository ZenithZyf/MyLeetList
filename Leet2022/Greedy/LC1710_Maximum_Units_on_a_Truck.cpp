class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(begin(boxTypes), end(boxTypes), [](const vector<int>& a, const vector<int>& b){
           return a[1] > b[1]; 
        });
        int ans = 0;
        for (const auto& b : boxTypes) {
            ans += b[1] * min(b[0], truckSize);
            if ((truckSize -= b[0]) <= 0) {
                break;
            }
        }
        return ans;
    }
};
