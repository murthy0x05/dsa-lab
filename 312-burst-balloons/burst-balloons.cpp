class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> balloons;
        balloons.push_back(1);
        for (int i = 0; i < n; i++)
            balloons.push_back(nums[i]);
        balloons.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n + 1; i >= 1; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                int maxCoins = INT_MIN;
                for (int k = i; k <= j - 1; k++) {
                    int coins = balloons[i - 1] * balloons[k] * balloons[j] +
                                dp[i][k] + dp[k + 1][j];
                    maxCoins = max<int>(maxCoins, coins);
                }

                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n + 1];
    }
};