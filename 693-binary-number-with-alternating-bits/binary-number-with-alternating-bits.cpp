class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lsb = (n & 1) ? 1 : 2;
        while (n > 0) {
            if ((n & 3) != lsb)
                return false;
            n >>= 2;
        }

        return true;
    }
};