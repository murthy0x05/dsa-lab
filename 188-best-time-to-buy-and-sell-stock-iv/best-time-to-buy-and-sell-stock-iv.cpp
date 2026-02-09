class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();

        vector<vector<vector<int>>> dp(N, vector<vector<int>>(k + 1, vector<int>(2, -1001)));
        dp[0][0][0] = 0; dp[0][0][1] = -prices[0];
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j][0] = dp[i - 1][j][0];
                if (j > 0)
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i]);
                
                dp[i][j][1] = dp[i - 1][j][1];
                if (j < k)
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }

        int result = 0;
        for (int j = 0; j <= k; j++) {
            result = max(result, dp[N - 1][j][0]);
        }

        return result;
    }
};