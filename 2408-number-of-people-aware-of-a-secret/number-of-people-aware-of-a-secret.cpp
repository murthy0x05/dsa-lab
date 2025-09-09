class Solution {
    const int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = i - delay; j >= i - forget + 1 && j > 0; j--) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }

        int sum = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            sum = (sum + dp[i]) % MOD;
        }

        return sum;
    }
};