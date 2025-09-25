class Solution {
    int dfs(auto& grid, int bi) {
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            if (grid[i][bi] == 1) {
                if ((bi + 1 >= c) || (bi + 1 < c && grid[i][bi + 1] == -1)) {
                    return -1;
                }
                bi++;
            } else {
                if ((bi - 1 < 0) || (bi - 1 >= 0 && grid[i][bi - 1] == 1)) {
                    return -1;
                }
                bi--;
            }
        }

        return bi;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        vector<int> b(c);
        for (int i = 0; i < c; i++) {
            b[i] = dfs(grid, i);
        }

        return b;
    }
};