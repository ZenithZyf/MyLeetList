class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.length() - 1, sz2 = num2.length() - 1;
        int carry = 0;
        string res = "";
        while (sz1 >= 0 || sz2 >= 0) {
            int c1 = sz1 >= 0 ? num1[sz1--] - '0' : 0;
            int c2 = sz2 >= 0 ? num2[sz2--] - '0': 0;
            int sum = c1 + c2 + carry;
            char cur = sum % 10 + '0';
            carry = sum / 10;
            res += cur;
        }
        if (carry) {
            res += carry + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
