class Solution {
    public int maxProfit(int[] prices) {
        final int N = prices.length;

        int[][] dp = new int[N][2];
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for (int i = 1; i < N; i++) {
            dp[i][0] = Math.max(prices[i] + dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = Math.max(-prices[i] + dp[i - 1][0], dp[i - 1][1]);
        }

        return Math.max(dp[N - 1][0], dp[N - 1][1]);
    }
}