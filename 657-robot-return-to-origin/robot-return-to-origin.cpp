class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (const char& move: moves) {
            if (move == 'U') {
                i -= 1;
            } else if (move == 'D') {
                i += 1;
            } else if (move == 'R') {
                j += 1;
            } else {
                j -= 1;
            }
        }

        return !i && !j;
    }
};