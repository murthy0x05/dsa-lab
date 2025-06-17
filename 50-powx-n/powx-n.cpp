class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        long long y = n;
        y = abs(y);
        
        while (y > 0) {
            if (y & 1) {
                result *= x;
            }
            x *= x;
            y = y >> 1;
        }

        return n < 0 ? 1 / result : result;
    }
};