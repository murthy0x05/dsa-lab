class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&
               1 == __builtin_popcount(n) &&
               0 == ((int)log2(n) & 1);
    }
};