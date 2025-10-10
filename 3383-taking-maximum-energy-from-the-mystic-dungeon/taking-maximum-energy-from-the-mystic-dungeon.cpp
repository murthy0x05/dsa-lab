class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        int result = INT_MIN;
        vector<int> dp(n);
        for (int i = n - 1; i >= n - k; i--) {
            dp[i] = energy[i];
            result = max(result, dp[i]);
        }

        for (int i = n - k - 1; i >= 0; i--) {
            dp[i] = energy[i] + dp[i + k];
            result = max(result, dp[i]);
        }

        return result;
    }
};