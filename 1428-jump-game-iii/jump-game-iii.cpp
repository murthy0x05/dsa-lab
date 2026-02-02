class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();

        vector<short> dp(n, -1);
        function<bool(int)> dfs = [&](int i) {
            if (i < 0 || i >= n) {
                return false;
            }
            if (dp[i] != -1) {
                return dp[i] ? true : false;
            }
            if (arr[i] == 0) {
                dp[i] = 1;
                return true;
            }

            dp[i] = 0;
            if (dfs(i + arr[i]) || dfs(i - arr[i])) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }

            return dp[i] ? true : false;
        };

        return dfs(start);
    }
};