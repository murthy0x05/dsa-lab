class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int n = grid.size();

        int dp[51][51][51];
        memset(dp, -1, sizeof(dp));

        dp[0][0][0] = grid[0][0];
        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < n; j1++) {
                for (int i2 = 0; i2 < n; i2++) {
                        int j2 = i1 + j1 - i2;
                        if (j2 < 0 || j2 >= n) {
                            continue;
                        }
                        if (grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                            dp[i1][j1][i2] = -1;
                            continue;
                        }
                        
                        int add = (i1 == i2 && j1 == j2) ? (grid[i1][j1]) : (grid[i1][j1] + grid[i2][j2]);
                        if (i1 > 0 && i2 > 0 && dp[i1 - 1][j1][i2 - 1] != -1) {
                            dp[i1][j1][i2] = max(dp[i1][j1][i2], add + dp[i1 - 1][j1][i2 - 1]);
                        }
                        if (j1 > 0 && j2 > 0 && dp[i1][j1 - 1][i2] != -1) {
                            dp[i1][j1][i2] = max(dp[i1][j1][i2], add + dp[i1][j1 - 1][i2]); 
                        }
                        if (i1 > 0 && j2 > 0 && dp[i1 - 1][j1][i2] != -1) {
                            dp[i1][j1][i2] = max(dp[i1][j1][i2], add + dp[i1 - 1][j1][i2]);
                        }
                        if (j1 > 0 && i2 > 0 && dp[i1][j1 - 1][i2 - 1] != -1) {
                            dp[i1][j1][i2] = max(dp[i1][j1][i2], add + dp[i1][j1 - 1][i2 - 1]);
                        }
                        // dp[i1][j1][i2][j2] = grid[i1][j1] + ((i1 != i2 || j1 != j2) * grid[i2][j2]) + max({
                        //     (i1 > 0 && i2 > 0) ? dp[i1 - 1][j1][i2 - 1][j2] : 0,
                        //     (j1 > 0 && j2 > 0) ? dp[i1][j1 - 1][i2][j2 - 1] : 0,
                        //     (i1 > 0 && j2 > 0) ? dp[i1 - 1][j1][i2][j2 - 1] : 0,
                        //     (j1 > 0 && i2 > 0) ? dp[i1][j1 - 1][i2 - 1][j2] : 0
                        // });
                }
            }
        }

        return max(dp[n - 1][n - 1][n - 1], 0);
    }
};