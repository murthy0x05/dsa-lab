class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int maxVal = 0;

        for (auto& r : grid)
            for (int v : r)
                maxVal = max(maxVal, v);

        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> best(maxVal + 1, INT_MAX), pref(maxVal + 1);

        best[grid[n-1][m-1]] = 0;

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i == n-1 && j == m-1) continue;

                int d = i+1<n ? dp[i+1][j] + grid[i+1][j] : INT_MAX;
                int r = j+1<m ? dp[i][j+1] + grid[i][j+1] : INT_MAX;

                dp[i][j] = min(d, r);
                best[grid[i][j]] = min(best[grid[i][j]], dp[i][j]);
            }
        }

        while (k--) {
            pref[0] = best[0];
            for (int i = 1; i <= maxVal; i++)
                pref[i] = min(pref[i-1], best[i]);

            for (int i = n-1; i >= 0; i--) {
                for (int j = m-1; j >= 0; j--) {
                    if (i == n-1 && j == m-1) continue;

                    int walk = min(
                        i+1<n ? dp[i+1][j] + grid[i+1][j] : INT_MAX,
                        j+1<m ? dp[i][j+1] + grid[i][j+1] : INT_MAX
                    );

                    dp[i][j] = min(walk, pref[grid[i][j]]);
                    best[grid[i][j]] = min(best[grid[i][j]], dp[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};