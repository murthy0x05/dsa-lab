class Solution {
    public int minFallingPathSum(int[][] matrix) {
        final int R = matrix.length,
                  C = matrix[0].length;

        for (int i = 1; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int got = Integer.MAX_VALUE;
                if (j > 0) {
                    got = Math.min(got, matrix[i - 1][j - 1]);
                }
                got = Math.min(got, matrix[i - 1][j]);
                if (j < R - 1) {
                    got = Math.min(got, matrix[i - 1][j + 1]);
                }

                matrix[i][j] += got;
            }
        }

        int result = matrix[R - 1][0];
        for (int j = 1; j < C; j++) {
            result = Math.min(result, matrix[R - 1][j]);
        }

        return result;
    }
}