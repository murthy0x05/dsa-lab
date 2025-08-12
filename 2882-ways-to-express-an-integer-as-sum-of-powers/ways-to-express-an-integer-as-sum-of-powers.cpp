#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;

        vector<int> powers;
        for (int k = 1; pow(k, x) <= n; ++k) {
            powers.push_back((int)pow(k, x));
        }

        int m = powers.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }

        return dp[n];
    }
};
