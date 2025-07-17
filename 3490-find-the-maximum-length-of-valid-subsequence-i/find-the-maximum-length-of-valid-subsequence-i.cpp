class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));

        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i] % 2;
            for (int prev = 0; prev < 2; prev++) {
                dp[curr][prev] = dp[prev][curr] + 1;
                max_len = max(max_len, dp[curr][prev]);
            }
        }

        return max_len;
    }
};