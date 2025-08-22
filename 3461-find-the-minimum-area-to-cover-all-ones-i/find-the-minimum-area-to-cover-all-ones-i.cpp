class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minRow = INT_MAX, minCol = INT_MAX;
        int maxRow = INT_MIN, maxCol = INT_MIN;
        int r = 1, c = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    minRow = min<int>(minRow, i + 1);
                    minCol = min<int>(minCol, j + 1);
                    maxRow = max<int>(maxRow, i + 1);
                    maxCol = max<int>(maxCol, j + 1);
                }
            }
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};