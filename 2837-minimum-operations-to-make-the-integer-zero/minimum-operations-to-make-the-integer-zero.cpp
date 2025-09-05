class Solution {
    using ll = long long;
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int op = 1; op < 61; op++) {
            ll diff = 1LL * num1 - op * 1LL * num2;
            if (diff < op) continue;

            if (__builtin_popcountll(diff) <= op) return op;
        }

        return -1;
    }
};