class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        unsigned long long result = 0;
        for (int i = 1, offset = 0; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                offset++;
            }
            result = ((result << offset) | i) % MOD;
        }

        return result;
    }
};