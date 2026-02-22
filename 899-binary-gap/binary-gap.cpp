class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bs(n);

        int len = 0;
        for (int prev = bs._Find_first(), i = prev + 1; i < 32; i++) {
            if (bs.test(i)) {
                len = max(len, i - prev);
                prev = i;
            }
        }

        return len;
    }
};