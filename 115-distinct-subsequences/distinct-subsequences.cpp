class Solution {
    using ull = unsigned long long;
public:
    int numDistinct(string s, string t) {
        const int N = s.size(),
                  M = t.size();
        if (N < M) {
            return 0;
        }

        // dp[i][j] = number of distinct subsequences of t.substr(0, j + 1) upto s_i.

        vector<vector<ull>> dp(N + 1, vector<ull>(M + 1, 0));
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] += dp[i][j];
                } 
            }
        }

        // for (int i = 0; i <= N; i++) {
        //     if (i == 0) {
        //         cout << "  * ";
        //         for (int j = 0; j < M; j++) {
        //             cout << t[j] << ' ';
        //         }
        //         cout << endl;
        //     }
        //     for (int j = 0; j <= M; j++) {
        //         if (j == 0) {
        //             if (i > 0)
        //                 cout << s[i - 1] << ' ';
        //             else
        //                 cout << "* ";
        //         }
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        // int result = 0;
        // for (int i = 0; i < N + 1; i++) {
        //     result += dp[i][M];
        // }

        return dp.back().back();
    }
};