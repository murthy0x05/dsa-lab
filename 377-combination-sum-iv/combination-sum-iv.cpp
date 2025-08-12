class Solution {
    using i128 = __int128_t;
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < n; i++) {
                if (j - nums[i] >= 0) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }

        return dp.back();
    }
};
