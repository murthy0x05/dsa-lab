class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> dp(N, -1); dp[0] = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(nums[i] - nums[j]) <= target && dp[j] != -1) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[N - 1];
    }
};