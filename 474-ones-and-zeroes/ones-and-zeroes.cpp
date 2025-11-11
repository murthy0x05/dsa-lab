class Solution {
    typedef pair<int, int> pii;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();

        vector<pii> zo(sz);
        for (int i = 0; i < sz; i++) {
            zo[i].first = count(strs[i].begin(), strs[i].end(), '0');
            zo[i].second = strs[i].size() - zo[i].first;
        }

        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m+1, vector<int>(n+1)));
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (zo[i - 1].first <= j && zo[i - 1].second <= k) {
                        dp[i][j][k] = max(dp[i - 1][j][k],
                                      1 + dp[i - 1][j - zo[i - 1].first][k - zo[i - 1].second]);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        return dp.back().back().back();
    }  
};