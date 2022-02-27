class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        const int n = num.size();
        vector<int> res;
        int carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (k == 0) {
                int cur = num[i];
                int sum = cur + carry;
                carry = sum / 10;
                res.emplace_back(sum % 10);
                continue;
            }
            int cur = k % 10;
            k = k / 10;
            int sum = cur + num[i] + carry;
            carry = sum / 10;
            res.emplace_back(sum % 10);
        }
        while (k > 0) {
            int cur = k % 10;
            k = k / 10;
            int sum = cur + carry;
            carry = sum / 10;
            res.emplace_back(sum % 10);
        }
        if (carry) {
            res.emplace_back(1);
        }
        int final_sum = 0;
        reverse(res.begin(), res.end());
        return res;
    }
};
