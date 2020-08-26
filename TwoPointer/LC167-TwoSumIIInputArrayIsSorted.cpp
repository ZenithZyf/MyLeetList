class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int small = 0;
        int large = numbers.size() - 1;
        while (small < large) {
            if (numbers[small] + numbers[large] == target)
                break;
            else if (numbers[small] + numbers[large] > target)
                --large;
            else
                ++small;
        }
        return {small + 1, large + 1};
    }
};
