class Solution {
    const int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2, ws = 0; i <= n; i++) {
            if (i - delay > 0)
                ws = (ws + dp[i - delay]) % MOD;
            if (i - forget > 0)
                ws = (ws - dp[i - forget] + MOD) % MOD;
            
            dp[i] = (dp[i] + ws) % MOD;
        }

        int sum = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            sum = (sum + dp[i]) % MOD;
        }

        return sum;
    }
};