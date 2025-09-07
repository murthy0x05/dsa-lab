class Solution {
public:
    vector<int> sumZero(int n) {
        if (1 == n) {
            return {0};
        } else if (2 == n) {
            return {-1, 1};
        } else {
            vector<int> result(n);
            if (n & 1) {
                for (int i = 0, val = -4, len = n/2 - 1; i < len; i++) {
                    result[i] = val--;
                }
                for (int i = n/2 + 2, val = 4; i < n; i++) {
                    result[i] = val++;
                }
                result[n/2 - 1] = -2;
                result[n/2] = -1;
                result[n/2 + 1] = 3;
            } else {
                for (int i = 0, val = -4, len = n/2; i < len; i++) {
                    result[i] = val--;
                }
                for (int i = n/2, val = 4; i < n; i++) {
                    result[i] = val++;
                }
            }

            return result;
        }
    }
};