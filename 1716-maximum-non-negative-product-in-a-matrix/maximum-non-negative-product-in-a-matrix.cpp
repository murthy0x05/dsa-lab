class Solution {
    typedef pair<long long, long long> pll;
    const int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int R = grid.size(),
                  C = grid[0].size();
        
        vector<vector<pll>> dp(R, vector<pll>(C, make_pair(-1LL, 1LL)));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j].first = dp[i][j].second = grid[i][j];
                } else if (i == 0) {
                    if (grid[i][j] == 0) {
                        dp[i][j].first = dp[i][j].second = 0LL;
                    } else if (grid[i][j] < 0) {
                        dp[i][j].first = grid[i][j] * (dp[i][j - 1].second);
                        dp[i][j].second = grid[i][j] * (dp[i][j - 1].first);
                    } else {
                        dp[i][j].first = grid[i][j] * (dp[i][j - 1].first);
                        dp[i][j].second = grid[i][j] * (dp[i][j - 1].second);
                    }
                } else if (j == 0) {
                    if (grid[i][j] == 0) {
                        dp[i][j].first = dp[i][j].second = 0LL;
                    } else if (grid[i][j] < 0) {
                        dp[i][j].first = grid[i][j] * (dp[i - 1][j].second);
                        dp[i][j].second = grid[i][j] * (dp[i - 1][j].first);
                    } else {
                        dp[i][j].first = grid[i][j] * (dp[i - 1][j].first);
                        dp[i][j].second = grid[i][j] * (dp[i - 1][j].second);
                    }
                } else {
                    if (grid[i][j] == 0) {
                        dp[i][j].first = dp[i][j].second = 0LL;
                    } else if (grid[i][j] < 0) {
                        dp[i][j].first = grid[i][j] * (max(dp[i - 1][j].second, dp[i][j - 1].second));
                        dp[i][j].second = grid[i][j] * (min(dp[i - 1][j].first, dp[i][j - 1].first));
                    } else {
                        dp[i][j].first = grid[i][j] * (min(dp[i - 1][j].first, dp[i][j - 1].first));
                        dp[i][j].second = grid[i][j] * (max(dp[i - 1][j].second, dp[i][j - 1].second));
                    }
                }
            }
        }


        if (dp.back().back().second < 0) {
            return -1;
        } else {
            return (dp.back().back().second % MOD);
        }
    }
};