class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> primes(n, true);
        primes[0] = false; primes[1] = false;
        int counter = 0;

        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                counter += 1;
                for (long j = (long)i * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        return counter;
    }
};