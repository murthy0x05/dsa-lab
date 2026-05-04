class Solution {
    public void rotate(int[][] matrix) {
        final int R = matrix.length,
                  C = matrix[0].length;

        for (int i = 0; i < R; i++) {
            for (int j = i + 1; j < C; j++) {
                matrix[i][j] = matrix[j][i] ^ matrix[i][j] ^ (matrix[j][i] = matrix[i][j]);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0, Cby2 = C >> 1; j < Cby2; j++) {
                matrix[i][j] = matrix[i][C - j - 1] ^ matrix[i][j] ^ (matrix[i][C - j - 1] = matrix[i][j]);
            }
        }
    }
}