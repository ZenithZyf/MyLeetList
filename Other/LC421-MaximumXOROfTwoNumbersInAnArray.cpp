class Solution {
public:
    // important property: a ^ b = c, then a ^ c = b, b ^ c = a
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 30; i >= 0; --i) {
            // mask for prefix
            mask |= (1 << i);
            unordered_set<int> s;
            for (const int num : nums) {
                // extract prefix of all nums
                s.insert(num & mask);
            }
            
            // suppose ith bit is 1
            int tmp = res | (1 << i);
            for (int pre : s) {
                if (s.count(pre ^ tmp)) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
