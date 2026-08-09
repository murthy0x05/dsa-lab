class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> pow = {0};
        for (int i = 1; pow[i - 1] <= n + 1; i++) {
            pow.push_back(i * i);
        }

        int mem[n + 1][2];
        memset(mem, -1, sizeof(mem));
        auto f = [&] (auto&& f, int N, bool alice) {
            if (N == 0) {
                return !alice;
            }

            if (mem[N][alice] != -1) {
                return (bool)mem[N][alice];
            }

            for (int i = 1; pow[i] <= N; i++) {
                if (alice) {
                    if (f(f, N - pow[i], !alice)) {
                        return (bool) (mem[N][alice] = true);
                    }
                } else {
                    if (!f(f, N - pow[i], !alice)) {
                        return (bool) (mem[N][alice] = false);
                    }
                }
            }

            return !alice;
        };

        return f(f, n, true);
    }
};