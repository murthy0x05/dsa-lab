class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int start = 0, end = 0;

        int maxIncome = 0, startPrice = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i-1] > prices[i]) {
                maxIncome += prices[i-1] - startPrice;
                startPrice = prices[i];
            }
        }

        return maxIncome + prices[n-1] - startPrice;
    }
}