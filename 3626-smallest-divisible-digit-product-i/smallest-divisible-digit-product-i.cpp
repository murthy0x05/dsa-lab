class Solution {
public:
    int helper(int x) {
        int res = 1;
        while (x) {
            res *= x % 10;
            if (!res) return res;
            x /= 10;
        }
        return res;
    }
    int smallestNumber(int n, int t) {
        if (n % 10 == 0) return n;
        while (true) {
            if (helper(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};