class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> nums(10);
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g) {
                bulls++;
            } else {
                // meet s nums++, meet g nums--
                if (nums[s] < 0) cows++;
                if (nums[g] > 0) cows++;
                nums[s]++;
                nums[g]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
