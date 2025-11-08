class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;

        int val = 0, x = n;
        while (x) {
            val = x;
            x = x & (x - 1);
        }

        return val * 2LL - 1 - minimumOneBitOperations(val ^ n);
    }
};