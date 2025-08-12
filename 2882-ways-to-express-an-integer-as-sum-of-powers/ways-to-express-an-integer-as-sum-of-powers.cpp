class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((int)pow(i, x));
        }

        int m = powers.size();
        vector<int> prev(n + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= m; i++) {
            vector<int> curr(n + 1, 0);
            for (int j = 0; j <= n; j++) {
                curr[j] = prev[j];
                if (j - powers[i - 1] >= 0) {
                    curr[j] = (curr[j] + prev[j - powers[i - 1]]) % MOD;
                }
            }
            prev = curr;
        }

        return prev.back();
    }
};