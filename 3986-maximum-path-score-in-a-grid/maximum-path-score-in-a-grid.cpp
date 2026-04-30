class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m + 1,
            vector<vector<int>>(n + 1, vector<int>(k + 1, (int)-1e9))
        );

        int res = find(m - 1, n - 1, 0, k, grid, dp);

        if (res < 0) return -1;
        return res;
    }

    int find(int i, int j, int cost, int k,
             vector<vector<int>>& grid,
             vector<vector<vector<int>>>& dp) {

        if (i < 0 || j < 0) return (int)-1e9;

        if (i == 0 && j == 0) return grid[0][0];

        if (dp[i][j][cost] != (int)-1e9)
            return dp[i][j][cost];

        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);

        if (newCost > k) return (int)-1e9;

        int up = find(i - 1, j, newCost, k, grid, dp);
        int left = find(i, j - 1, newCost, k, grid, dp);

        return dp[i][j][cost] = max(up, left) + grid[i][j];
    }
};