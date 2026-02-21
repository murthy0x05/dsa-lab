class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // bitset<32> isPrime("10100000100010100010100010101100");
        bitset<32> isPrime(2693408940);
        
        int count = 0;
        for (int i = left; i <= right; i++) {
            count += isPrime.test(__builtin_popcount(i));
        }

        return count;
    }
};