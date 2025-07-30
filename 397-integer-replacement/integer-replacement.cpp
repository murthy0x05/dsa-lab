class Solution {
    unordered_map<long, int> mem;
public:
    int integerReplacement(long n) {
        if (n == 1) {
            return 0;
        }

        if (mem.count(n)) {
            return mem[n];
        }
        if (n & 1) {
            return mem[n] = 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
        } else {
            return mem[n] = 1 + integerReplacement(n / 2);
        }
    }
};