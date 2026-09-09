class Solution {
    public long numberOfRightTriangles(int[][] grid) {
        final int R = grid.length, C = grid[0].length;

        long[][] ps = new long[R + 1][C + 1];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + grid[i][j];
            }
        }

        long result = 0L;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) {
                    long UP = ps[i + 1][j + 1] - ps[0][j + 1] - ps[i + 1][j] + ps[0][j] - 1;
                    long DOWN = ps[R][j + 1] - ps[i][j + 1] - ps[R][j] + ps[i][j] - 1;
                    long LEFT = ps[i + 1][j + 1] - ps[i][j + 1] - ps[i + 1][0] + ps[i][0] - 1;
                    long RIGHT = ps[i + 1][C] - ps[i][C] - ps[i + 1][j] + ps[i][j] - 1;

                    result += UP * LEFT + UP * RIGHT + LEFT * DOWN + RIGHT * DOWN;
                }
            }
        }

        return result;
    }
}