class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int first = 0, second = 0;
        vector<vector<int>> ans;
        while (first < firstList.size() && second < secondList.size()) {
            const int start = max(firstList[first][0], secondList[second][0]);
            const int end = min(firstList[first][1], secondList[second][1]);
            if (start <= end) {
                ans.push_back({start, end});
            }
            if (firstList[first][1] < secondList[second][1]) {
                ++first;
            } else {
                ++second;
            }
        }
        return ans;
    }
};
