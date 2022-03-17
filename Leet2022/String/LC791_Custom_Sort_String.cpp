class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> index(128, INT_MAX);
        int idx = 0;
        for (char o : order) {
            if (index[o] == INT_MAX) {
                index[o] = idx++;
            }
        }
        std::sort(s.begin(), s.end(), [&index](const char a, const char b) {
            return index[a] < index[b];
        });
        return s;
    }
};
