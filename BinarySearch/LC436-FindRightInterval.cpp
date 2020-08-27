class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < intervals.size(); ++i) {
            arr.emplace_back(make_pair(intervals[i][0], i));
        }
        sort(arr.begin(), arr.end());
        vector<int> result;
        for (int i = 0; i < intervals.size(); ++i) {
            result.push_back(findFirstBig(arr, intervals[i][1]));
        }
        return result;
    }
private:
    int findFirstBig(vector<pair<int, int>>& arr, int larger) {
        int l = 0;
        int r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first >= larger)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == arr.size()) return -1;
        return arr[l].second;
    }
};
