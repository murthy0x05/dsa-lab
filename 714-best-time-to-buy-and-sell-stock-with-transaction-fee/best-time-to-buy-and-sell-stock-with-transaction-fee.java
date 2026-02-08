class Solution {
    // Greedy Solution
    public int maxProfit(int[] prices, int fee) {
        final int N = prices.length;

        int prev = prices[0], profit = 0;
        for (int i = 1; i < N; i++) {
            if ((prices[i] - prev - fee) > 0) {
                profit += prices[i] - prev - fee;
                prev = prices[i] - fee;
            } else {
                prev = Math.min(prev, prices[i]);
            }
        }

        return profit;
    }
}