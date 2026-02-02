class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        const int r = grid.size(),
                  c = grid[0].size(),
                  INF = 5001;

        vector<vector<int>> dp(r, vector<int>(c, INF));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    for (int k = 0; k < c; k++) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                    }
                    dp[i][j] += grid[i][j];
                }
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }
};