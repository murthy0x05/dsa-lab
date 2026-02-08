class Solution {
    using ll = long long;
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(3, vector<long long>(2)));
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        dp[0][1][1] = dp[0][2][1] = INT_MIN;

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j][0] = dp[i - 1][j][0];
                if (j > 0)
                    dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i]);

                dp[i][j][1] = dp[i - 1][j][1];
                if (j < 2)
                    dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }

        ll result = 0;
        for (int j = 0; j <= 2; j++) {
            result = max<ll>(result, dp[N - 1][j][0]);
        }
        return result;

    }
};