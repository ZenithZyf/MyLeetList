class Difference {
public:
    Difference(vector<int> nums) {
        diff.resize(nums.size(), 0);
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    
    void increment(const int i, const int j, const int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }
    
    vector<int> result() {
        vector<int> res(diff.size(), 0);
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); ++i) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
    
private:
    vector<int> diff;
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length, 0);
        Difference df(nums);
        for (auto& update : updates) {
            int i = update[0];
            int j = update[1];
            int val = update[2];
            df.increment(i, j, val);
        }
        return df.result();
    }
};
