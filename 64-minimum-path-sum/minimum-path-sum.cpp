class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                } else if (i - 1 >= 0) {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                } else if (j - 1 >= 0) {
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                }
            }
        }

        // for (auto& row: dp) {
        //     for (int ele: row) {
        //         cout << ele << ' ';
        //     }
        //     cout << endl;
        // }

        return dp.back().back();
    }
};