class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(matrix);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1)
                    dp[i][j] = 1 + min<int>({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                result += dp[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            result += dp[i][0];
        }
        for (int i = 1; i < m; i++) {
            result += dp[0][i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }

        return result;
    }
};