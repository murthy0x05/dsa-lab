class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (i == 0) {
        //             dp[i][j] = max(0, prices[j] - prices[i]);
        //         } else {
        //             dp[i][j] = max(0, prices[j] - prices[i]);
        //             dp[i][j] += dp[i - 1][i];
        //             dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        //         }
        //         dp[i][j] = max({dp[i][j], dp[i][j - 1]});
        //     }
        // }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        
        for (int t = 1; t <= k; t++) {
            int maxDiff = -prices[0];
            
            for (int i = 1; i < n; i++) {
                dp[i][t] = max(dp[i-1][t], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[i][t-1] - prices[i]);
            }
        }

        for (auto& row: dp) {
            for (int ele: row) {
                if (ele == -1) {
                    cout << " ";
                } else {
                    cout << ele;
                }
                cout << " ";
            }
            cout << endl;
        }

        return dp[n - 1].back();
    }
};