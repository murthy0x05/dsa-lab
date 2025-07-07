class Solution {
public:
    inline int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int i = 1; i <= amount; i++)
            dp[0][i] = 1e5;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    int include = 1 + dp[i][j - coins[i - 1]];
                    int exclude = dp[i - 1][j];
                    dp[i][j] = min(include, exclude);
                }
            }
        }

        return dp.back().back() > 1e4 ? -1 : dp.back().back();
    }
};