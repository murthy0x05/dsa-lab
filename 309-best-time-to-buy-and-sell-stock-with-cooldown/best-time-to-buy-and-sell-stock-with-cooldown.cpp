class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if (N == 1) {
            return 0;
        }

        vector<vector<int>> dp(N, vector<int>(2, -1001));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            if (i - 2 >= 0) {
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
                dp[i][0] = max(dp[i][0], dp[i - 2][1] + prices[i]);
            } else {
                dp[i][1] = max(dp[i - 1][1], -prices[i]);
            }
        }

        return dp[N - 1][0];
    }
};