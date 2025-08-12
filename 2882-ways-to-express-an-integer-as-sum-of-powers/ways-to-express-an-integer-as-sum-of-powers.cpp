class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }

        int m = powers.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (const int& power: powers) {
            for (int j = n; j >= power; j--) {
                if (j - power >= 0) {
                    dp[j] = (dp[j] + dp[j - power]) % MOD;
                }
            }
        }

        return dp.back();
    }
};