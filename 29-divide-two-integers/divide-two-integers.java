class Solution {
    public int divide(int dividend, int divisor) {
        long n = Math.abs((long) dividend);
        long d = Math.abs((long) divisor);

        if (0 == n) return 0;

        long q = 0;
        while (n >= d) {
            int p = 0;
            while ((d << p) <= n) p++;
            n -= d << (p - 1);
            q += 1L << (p - 1);
        }

        if ((dividend < 0) ^ (divisor < 0)) {
            q = ~q + 1;
        }

        if (q > Integer.MAX_VALUE) q = Integer.MAX_VALUE;
        if (q < Integer.MIN_VALUE) q = Integer.MIN_VALUE;

        return (int)q;
    }
}