class Solution {
public:
    int minMoves(vector<int>& nums) {
        const long sum = accumulate(nums.cbegin(), nums.cend(), 0L);
        const long min_ele = *min_element(nums.cbegin(), nums.cend());
        return sum - nums.size() * min_ele;
    }
};
