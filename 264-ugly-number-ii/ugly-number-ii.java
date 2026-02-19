class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];

        dp[0] = 1;
        int i2 = 0, j3 = 0, k5 = 0;
        int multiple2 = 2,
            multiple3 = 3,
            multiple5 = 5;
        for (int i = 1; i < n; i++) {
            dp[i] = Math.min(multiple2, Math.min(multiple3, multiple5));

            if (dp[i] == multiple2) {
                multiple2 = 2 * dp[++i2];
            }
            if (dp[i] == multiple3) {
                multiple3 = 3 * dp[++j3];
            }
            if (dp[i] == multiple5) {
                multiple5 = 5 * dp[++k5];
            }
        }

        return dp[n - 1];
    }
}