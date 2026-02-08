class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = max(prices[i] + dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = max(-prices[i] + dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[N - 1][0], dp[N - 1][1]);
    }
};