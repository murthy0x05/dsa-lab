class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int r = grid.size(),
                  c = grid[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};
        function<int(int, int)> dfs = [&](int i, int j) {
            grid[i][j] *= -1;
            int best = 0;
            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d];
                int nj = j + dir[d + 1];
                if (ni >= 0 && nj >= 0 && ni < r && nj < c && grid[ni][nj] > 0) {
                    best = max(best, dfs(ni, nj));
                }
            }
            grid[i][j] *= -1;

            return best + grid[i][j];
        };

        int result = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] > 0) {
                    result = max(result, dfs(i, j));
                }
            }
        }

        return result;
    }
};