class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int r = grid.size(),
                  c = grid[0].size();
        
        int dp[r][c][c];
        memset(dp, -1, sizeof(dp));

        // for (int i = 0; i < r; i++) {
        //     for (int j2 = 0; j2 < c; j2++) {
        //         dp[i][0][j2] = grid[0][0];
        //     }
        // }
        // for (int i = 0; i < r; i++) {
        //     for (int j1 = 0; j1 < c; j1++) {
        //         dp[i][j1][c - 1] += grid[0][c - 1];
        //     }
        // }

        dp[0][0][c - 1] = grid[0][0] + grid[0][c - 1];

        for (int i = 1; i < r; i++) {
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {
                    int add = grid[i][j1];
                    if (j1 != j2) {
                        add += grid[i][j2];
                    }

                    if (i > 0 && j1 > 0 && j2 > 0 && dp[i - 1][j1 - 1][j2 - 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 - 1][j2 - 1]);
                    }
                    if (i > 0 && j1 > 0 && dp[i - 1][j1 - 1][j2] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 - 1][j2]);
                    }
                    if (i > 0 && j1 > 0 && (j2 + 1) < c && dp[i - 1][j1 - 1][j2 + 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 - 1][j2 + 1]);
                    }

                    if (i > 0 && j2 > 0 && dp[i - 1][j1][j2 - 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1][j2 - 1]);
                    }
                    if (i > 0 && dp[i - 1][j1][j2] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1][j2]);
                    }
                    if (i > 0 && (j2 + 1) < c && dp[i - 1][j1][j2 + 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1][j2 + 1]);
                    }

                    if (i > 0 && (j1 + 1) < c && j2 > 0 && dp[i - 1][j1 + 1][j2 - 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 + 1][j2 - 1]);
                    }
                    if (i > 0 && (j1 + 1) < c && dp[i - 1][j1 + 1][j2] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 + 1][j2]);
                    }
                    if (i > 0 && (j1 + 1) < c && (j2 + 1) < c && dp[i - 1][j1 + 1][j2 + 1] != -1) {
                        dp[i][j1][j2] = max(dp[i][j1][j2], add + dp[i - 1][j1 + 1][j2 + 1]);
                    }
                }
            }
        }


        int result = 0;
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                result = max(result, dp[r - 1][j1][j2]);
            }
        }

        return result;
    }
};