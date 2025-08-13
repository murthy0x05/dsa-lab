class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        else {
            int maxPower = log(INT_MAX) / log(3);
            int maxValue = pow(3, maxPower);
            return maxValue % n == 0;
        }

        // 0: 1
        // 1: 11
        // 2: 1001
        // 3: 11011
        // 4: 1010001
    }
};