class Solution {
    using pii = pair<int, int>;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int R = board.size(),
                  C = board[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<pii>> dp(R, vector<pii>(C, make_pair(0, 0)));
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                if (board[i][j] == 'X') {
                    continue;
                }

                if (i == R - 1 && j == C - 1) {
                    dp[i][j].first = 0;
                    dp[i][j].second = 1;
                    continue;
                } else if (i == R - 1) {
                    dp[i][j] = dp[i][j + 1];
                } else if (j == C - 1) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    int Max = max({dp[i + 1][j].first, dp[i][j + 1].first, dp[i + 1][j + 1].first});
                    if (dp[i + 1][j].first == Max) {
                        dp[i][j].second = dp[i + 1][j].second % MOD;
                    }
                    if (dp[i][j + 1].first == Max) {
                        dp[i][j].second = (dp[i][j].second + 0LL + dp[i][j + 1].second) % MOD;
                    }
                    if (dp[i + 1][j + 1].first == Max) {
                        dp[i][j].second = (dp[i][j].second + 0LL + dp[i + 1][j + 1].second) % MOD;
                    }
                    dp[i][j].first = Max;
                }
                if (isdigit(board[i][j])) dp[i][j].first += board[i][j] - '0';
            }
        }


        return {dp[0][0].second == 0 ? 0 : dp[0][0].first, dp[0][0].second};
    }
};