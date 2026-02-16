class Solution {
public:
    int reverseBits(int n) {
        bitset<32> bs(n);

        for (int i = 0; i < 16; i++) {
            bs[i] = bs[31 - i] ^ bs[i] ^ (bs[31 - i] = bs[i]);
        }

        return bs.to_ulong();
    }
};  