class Solution {
public:
    bool isRobotBounded(string instructions) {
        int d = 0; // 0 forward; 1 right; 2 backwoard; 3 left
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int x = 0;
        int y = 0;
        
        for (const char ch : instructions) {
            switch (ch) {
                case 'L':
                    d += 3;
                    break;
                case 'R':
                    d += 1;
                    break;
                case 'G':
                    x += dx[d % 4];
                    y += dy[d % 4];
                    break;
            }
        }
        
        return ((x == 0 && y == 0) || d % 4 != 0);
    }
};
