class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char c : tasks) {
            ++count[c - 'A'];
        }
        const int max_count = *max_element(count.cbegin(), count.cend());
        size_t ans = (max_count - 1) * (n + 1);
        ans += std::count_if(count.cbegin(), count.cend(), [max_count](int c){ return c == max_count; });
        return max(tasks.size(), ans);
    }
};
