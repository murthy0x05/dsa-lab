class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> mem(n + 1, vector<int>(k + 1, -1));
        function<int(int, int)> f = [&] (int E, int N) {
            if (E <= 1) {
                return N;
            }
            if (N <= 1) {
                return N;
            }

            // cout << E << ' ' << N << endl;

            if (mem[N][E] != -1)
                return mem[N][E];
            
            int moves = N;

            int l = 0, h = N;
            while (l <= h) {
                int m = l + ((h - l) >> 1);
                
                int broke = f(E - 1, m - 1);
                int survived = f(E, N - m);

                moves = min(moves, max(broke, survived) + 1);
                if (broke < survived) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }

            // for (int i = 1; i < N; i++) {
            //     int M = max(f(E - 1, i - 1), f(E, N - i)) + 1;
            //     moves = min(moves, M);
            // }

            return mem[N][E] = moves;
        };

        return f(k, n);
    }
};