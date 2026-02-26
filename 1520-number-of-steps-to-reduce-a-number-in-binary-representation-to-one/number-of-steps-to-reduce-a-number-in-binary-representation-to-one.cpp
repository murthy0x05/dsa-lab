class Solution {
public:
    int numSteps(string s) {
        const int N = s.size();

        int ops = 0, carry = 0;
        for (int i = N - 1; i >= 1; i--) {
            if (s[i] == '0') {
                if (carry > 0) {
                    ops += 2;
                } else {
                    ops++;
                }
            } else {
                if (carry > 0) {
                    ops++;
                } else {
                    carry = 1;
                    ops += 2;
                }
            }
        }
        if (carry > 0) {
            ops++;
        }

        return ops;
    }
};