class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int index = 0;
        int curMax = releaseTimes[0];
        for (int i = 1; i < releaseTimes.size(); ++i) {
            int curTime = releaseTimes[i] - releaseTimes[i - 1];
            if (curTime == curMax) {
                if (keysPressed.at(i) > keysPressed.at(index)) {
                    index = i;
                }
            } else if (curTime > curMax) {
                index = i;
                curMax = curTime;
            }
                
        }
        return keysPressed.at(index);
    }
};
