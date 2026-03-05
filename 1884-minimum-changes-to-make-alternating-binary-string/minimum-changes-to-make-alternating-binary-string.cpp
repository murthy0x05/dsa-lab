class Solution {
public:
    int minOperations(string s) {
        const int N = s.size();

        int count1 = 0, count2 = 0;
        bool bit1 = false, bit2 = true;
        for (int i = 0; i < N; i++) {
            if ((s[i] - '0') == bit1) {
                count1++;
            }
            if ((s[i] - '0') == bit2) {
                count2++;
            }

            bit1 = !bit1;
            bit2 = !bit2;
        }

        return min(count1, count2);
    }
};