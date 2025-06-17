class Solution {
    public double myPow(double x, int n) {
        long y = n;
        y = Math.abs(y);

        double result = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                result *= x;
            }
            x = x * x;
            y /= 2;
        }

        return n < 0 ? 1 / result : result;
    }
}