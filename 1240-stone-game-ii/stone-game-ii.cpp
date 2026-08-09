class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int N = piles.size();

        vector<vector<vector<int>>> mem(N, vector<vector<int>>(2 * N, vector<int>(2, -1)));
        function<int(int, int, bool)> f = [&] (int i, int M, bool alice) {
            if (i >= N) {
                return 0;
            }

            if (mem[i][M][alice] != -1) {
                return mem[i][M][alice];
            }

            int procure = alice ? INT_MIN : INT_MAX;
            int got = 0;
            for (int X = 0; X < 2 * M and i + X < N; X++) {
                got += piles[i + X];
                if (alice) {
                    procure = max(procure, got + f(i + X + 1, max(M, X + 1), !alice));
                } else {
                    procure = min(procure, f(i + X + 1, max(M, X + 1), !alice));
                }
            }

            return mem[i][M][alice] = procure;
        };

        return f(0, 1, true);
    }
};