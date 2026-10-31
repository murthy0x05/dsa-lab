
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int R = grid.size();
        const int C = grid[0].size();
        const int MOD = 1e9 + 7;
        
        vector<vector<array<long long, 2>>> dp(
            R, vector<array<long long, 2>>(C, {0, 0})
        );

        if (R == 1 && C == 1) return 1;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                long long ways;

                if (i == 0 && j == 0) {
                    ways = 1;
                }
                else if (i == R - 1 && j == C - 1) {
                    return (dp[i][j][0] + dp[i][j][1]) % MOD;
                }
                else if (grid[i][j] == 1) {
                    if (dp[i][j][0]) {
                        if (i + 1 < R) {
                            dp[i + 1][j][1] =
                                (dp[i + 1][j][1] + dp[i][j][0]) % MOD;
                        }
                    }

                    if (dp[i][j][1]) {
                        if (j + 1 < C) {
                            dp[i][j + 1][0] =
                                (dp[i][j + 1][0] + dp[i][j][1]) % MOD;
                        }
                    }

                    continue;
                }
                else {
                    ways = (dp[i][j][0] + dp[i][j][1]) % MOD;
                }

                if (j + 1 < C) {
                    dp[i][j + 1][0] =
                        (dp[i][j + 1][0] + ways) % MOD;
                }

                if (i + 1 < R) {
                    dp[i + 1][j][1] =
                        (dp[i + 1][j][1] + ways) % MOD;
                }
            }
        }

        return 0;
    }
};
