class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int inter = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            inter ^= nums[i];
        }
        int res = 1;
        for (int i = 0; i < 32; ++i) {
            if ((inter >> i) & 1) {
                res = 1 << i;
                break;
            }
        }
        int type0 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & res) {
                type0 ^= nums[i];
            }
        }
        return {type0, type0 ^ inter};
    }
};
