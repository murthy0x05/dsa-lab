class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> prev(c, vector<int>(K, 0));
        prev[0][(grid[0][0] % K)]++;
        for (int i = 1; i < c; i++) {
            for (int k = 0; k < K; k++) {
                if (prev[i - 1][k] > 0) {
                    prev[i][(grid[0][i] + k) % K] += prev[i - 1][k];
                    prev[i][(grid[0][i] + k) % K] %= MOD;
                }
            }
        }

        for (int i = 1; i < r; i++) {
            vector<vector<int>> curr(c, vector<int>(K, 0));
            for (int k = 0; k < K; k++) {
                if (prev[0][k] > 0) {
                    curr[0][(grid[i][0] + k) % K] += prev[0][k];
                    curr[0][(grid[i][0] + k) % K] %= MOD;
                }
            }
            for (int j = 1; j < c; j++) {
                for (int k = 0; k < K; k++) {
                    if (curr[j - 1][k] > 0) {
                        curr[j][(grid[i][j] + k) % K] += curr[j - 1][k];
                        curr[j][(grid[i][j] + k) % K] %= MOD;
                    }
                    if (prev[j][k] > 0) {
                        curr[j][(grid[i][j] + k) % K] += prev[j][k];
                        curr[j][(grid[i][j] + k) % K] %= MOD;
                    }
                }
            }
            prev = curr;
        }

        return prev.back().front();
    }
};