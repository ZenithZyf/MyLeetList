// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row = 0;
        int col = 0;
        int idx = 49;
        while (idx > 40) {
            row = rand7();
            col = rand7();
            idx = 7 * (row - 1) + col;
        }
        return (idx - 1) % 10 + 1;
    }
};
