class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(K, 0)));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j][grid[i][j] % K]++;
                } else if (i == 0) {
                    for (int k = 0; k < K; k++) {
                        if (dp[i][j - 1][k] > 0) {
                            dp[i][j][(grid[i][j] + k) % K] += dp[i][j - 1][k];
                            dp[i][j][(grid[i][j] + k) % K] %= MOD;
                        }
                    }
                } else if (j == 0) {
                    for (int k = 0; k < K; k++) {
                        if (dp[i - 1][j][k] > 0) {
                            dp[i][j][(grid[i][j] + k) % K] += dp[i - 1][j][k];
                            dp[i][j][(grid[i][j] + k) % K] %= MOD;
                        }
                    }
                } else {
                    for (int k = 0; k < K; k++) {
                        if (dp[i][j - 1][k] > 0) {
                            dp[i][j][(grid[i][j] + k) % K] += dp[i][j - 1][k];
                            dp[i][j][(grid[i][j] + k) % K] %= MOD;
                        }
                    }
                    for (int k = 0; k < K; k++) {
                        if (dp[i - 1][j][k] > 0) {
                            dp[i][j][(grid[i][j] + k) % K] += dp[i - 1][j][k];
                            dp[i][j][(grid[i][j] + k) % K] %= MOD;
                        }
                    }
                }
            }
        }

        return dp[r - 1][c - 1][0];
    }
};