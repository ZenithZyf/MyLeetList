class Solution {
public:
    int get(int x) {
        int bit = 0;
        while(x) {
            bit += x % 2;
            x /= 2;
        }
        return bit;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit_nums(10001);
        for (int i = 0; i < arr.size(); i++) {
            bit_nums[arr[i]] = get(arr[i]);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (bit_nums[x] < bit_nums[y])
                return true;
            else if (bit_nums[x] > bit_nums[y])
                return false;
            else
                return x < y;
        });
        return arr;
    }
};
