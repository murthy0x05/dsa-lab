class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            return *max_element(nums.begin(), nums.end());
        }

        // similar to the previous version but we will assume once that we didn't rob house 1 and once without robbing last house.

        vector<int> dp(n);
        dp[0] = nums[0]; dp[1] = nums[1]; dp[2] = nums[2] + dp[0];
        for (int i = 3; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], nums[i] + max(dp[i - 2], dp[i - 3]));
        }
        int result = dp[n - 2];

        dp[0] = 0; dp[1] = nums[1]; dp[2] = nums[2];
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + max(dp[i - 2], dp[i - 3]));
        }

        return max(result, dp[n - 1]);
    }
};