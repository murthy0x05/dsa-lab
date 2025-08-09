class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else
            return 1 == __builtin_popcount(n);

    }
};