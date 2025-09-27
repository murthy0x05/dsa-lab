class Solution {
    using ll = long long;
public:
    int divide(int dividend, int divisor) {
        ll n = abs((ll)dividend),
           d = abs(1LL * divisor);

        if (!n) return 0;
        short sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        ll q = n;
        if (d != 1) {
            q = 0;
            while (n >= d) {
                ll p = 0;
                while ((d << p) <= n) p++;
                q += 1 << (p - 1);
                n -= (d << (p - 1));
            }
        }
        
        q *= sign;
        if (q > INT_MAX) q = INT_MAX;
        if (q < INT_MIN) q = INT_MIN;

        return q;

        // 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0
        // 1 * 2^1 + 1 * 2^0d

        
        

    }
};