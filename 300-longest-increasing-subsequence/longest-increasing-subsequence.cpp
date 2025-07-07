class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n1 = nums.size();
        set<int> temp;
        for (int num: nums)
            temp.insert(num);
        int n2 = 0;
        vector<int> sorted(temp.size());
        for (int var: temp) {
            sorted[n2] = var;
            n2 += 1;
        }

        vector<vector<int>> dp(n2+1, vector<int>(n1+1, 0));
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < n1; j++) {
                if (nums[j] == sorted[i]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[n2][n1];
    }
};