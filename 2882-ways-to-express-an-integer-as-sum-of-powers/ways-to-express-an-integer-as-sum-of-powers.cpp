class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; ; i++) {
            long long val = 1;
            for (int j = 0; j < x; j++) val *= i;
            if (val > n) break;
            powers.push_back((int)val);
        }

        int m = powers.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - powers[i - 1] >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - powers[i - 1]]) % MOD;
                }
            }
        }

        return dp.back().back();
    }
};