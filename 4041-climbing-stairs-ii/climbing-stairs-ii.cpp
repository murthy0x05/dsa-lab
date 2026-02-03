class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int INF = 1e9 + 10;

        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (i >= 2) {
                dp[i] = min(dp[i - 2] + 4, dp[i]);
            }
            if (i >= 3) {
                dp[i] = min(dp[i - 3] + 9, dp[i]);
            }
            dp[i] += costs[i - 1];
        }

        return dp.back();
    }
};