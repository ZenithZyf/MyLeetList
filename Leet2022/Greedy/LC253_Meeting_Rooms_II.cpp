class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mRooms;
        for (auto i : intervals) {
            ++mRooms[i[0]];
            --mRooms[i[1]];
        }
        int rooms = 0;
        int res = 0;
        for (auto m : mRooms) {
            res = std::max(res, rooms += m.second);
        }
        return res;
    }
};
