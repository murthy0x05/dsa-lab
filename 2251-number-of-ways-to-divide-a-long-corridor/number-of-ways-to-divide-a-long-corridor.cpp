class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        
        int result = 1,
            seats = 0;
        for (int i = 0, ways = 1; i < n; i++) {
            if (seats < 2) {
                seats += (corridor[i] == 'S');
            } else {
                if (corridor[i] == 'P') {
                    ways++;
                } else {
                    result = (result * 1LL * ways) % MOD;
                    ways = seats = 1;
                }
            }
        }

        if (seats < 2) {
            return 0;
        }

        return result;



        return 0;
    }
};