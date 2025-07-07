class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        vector<vector<int>> dp(squares.size() + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1e5;
        }

        for (int i = 1; i <= squares.size(); i++) {
            for (int j = 1; j <= n; j++) {
                if (j < squares[i - 1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    int include = 1 + dp[i][j - squares[i - 1]];
                    int exclude = dp[i - 1][j];
                    dp[i][j] = min(include, exclude);
                }
            }
        }

        // for (auto& row: dp) {
        //     for (int ele: row) {
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }

        return dp.back().back();
    }
};