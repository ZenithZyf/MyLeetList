class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(128, 0);
        for (int i = 0; i < s.length(); ++i) {
            last[s[i]] = i;
        }
        int start = 0;
        int end = 0;
        vector<int> res;
        for (int i = 0; i < s.length(); ++i) {
            end = std::max(end, last[s[i]]);
            if (i == end) {
                res.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
