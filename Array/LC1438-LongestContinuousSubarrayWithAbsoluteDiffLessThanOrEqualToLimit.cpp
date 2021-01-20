class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int res = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!max_q.empty() && nums[r] > max_q.back())
                max_q.pop_back();
            while (!min_q.empty() && nums[r] < min_q.back())
                min_q.pop_back();
            max_q.push_back(nums[r]);
            min_q.push_back(nums[r]);
            while (max_q.front() - min_q.front() > limit) {
                if (max_q.front() == nums[l]) max_q.pop_front();
                if (min_q.front() == nums[l]) min_q.pop_front();
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
