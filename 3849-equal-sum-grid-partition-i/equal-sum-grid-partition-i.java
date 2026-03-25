class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        final int R = grid.length,
                  C = grid[0].length;

        long[][] ps = new long[R + 1][C + 1];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + grid[i][j];
            }
        }

        if ((ps[R][C] & 1) == 1) {
            return false;
        }

        for (int i = 1; i < R; i++) {
            if (ps[i][C] == (ps[R][C] - ps[i][C])) {
                return true;
            }
        }
        for (int j = 1; j < C; j++) {
            if (ps[R][j] == (ps[R][C] - ps[R][j])) {
                return true;
            }
        }

        return false;
    }
}