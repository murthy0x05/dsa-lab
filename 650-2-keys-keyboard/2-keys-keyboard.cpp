class Solution {
public:
    int minSteps(int n) {
        
        vector<int> dp(n + 1, n + 1);
        dp[1] = dp[0] = 0;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + 1 + (i/j - 1));
                }
            }
        }

        return dp.back();
    }
};