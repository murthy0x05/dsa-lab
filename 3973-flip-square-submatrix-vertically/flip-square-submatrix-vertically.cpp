class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x, half = x + (k >> 1), full = (y + k); i < half; i++) {
            for (int j = y; j < full; j++) {
                swap(grid[i][j], grid[2 * x + k - i - 1][j]);
            }
        }

        return grid;
    }
};