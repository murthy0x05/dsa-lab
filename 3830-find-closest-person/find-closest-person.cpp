class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs<int>(x - z) == abs<int>(y - z)) {
            return 0;
        } else {
            if (abs<int>(x - z) > abs<int>(y - z)) {
                return 2;
            } else {
                return 1;
            }
        }
    }
};