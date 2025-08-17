class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        vector<double> dp(n + 1);
        dp[0] = 1.0;

        double currProb = dp[0];
        for (int i = 1; i <= n; i++) {
            dp[i] = currProb / (double)maxPts;
            if (i < k) {
                currProb += dp[i];
            }
            if (i - maxPts >= 0) {
                currProb -= dp[i - maxPts];
            }
        }        

        double ans = 0.0;
        for (int i = k; i <= n; i++) {
            ans += dp[i];
        }

        return ans;
    }
};