class Solution {
    private int R, C;
    private int[] dir = new int[]{-1, 0, 1, 0, -1};
    private int[][] mem = null;
    private int dfs(int[][] matrix, int i, int j) {
        if (mem[i][j] != 0) {
            return mem[i][j];
        }

        int maxPath = 0;
        for (int d = 0; d < 4; d++) {
            int ni = i + dir[d],
                nj = j + dir[d + 1];
            if (ni >= 0 && nj >= 0 && ni < R && nj < C && matrix[i][j] < matrix[ni][nj]) {
                maxPath = Math.max(maxPath, dfs(matrix, ni, nj));
            }
        }

        return mem[i][j] = 1 + maxPath;
    }
    public int longestIncreasingPath(int[][] matrix) {
        this.R = matrix.length;
        this.C = matrix[0].length;
        this.mem = new int[R][C];

        int longest = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                longest = Math.max(longest, dfs(matrix, i, j));
            }
        }

        // for (int i = 0; i < R; i++) {
        //     for (int j = 0; j < C; j++) {
        //         System.out.print(mem[i][j] + ", ");
        //     }
        //     System.out.println();
        // }

        return longest;
    }
}

// Tabulation: Tried and pissed off
// class Solution {
//     public int longestIncreasingPath(int[][] matrix) {
//         final int R = matrix.length,
//                   C = matrix[0].length;

//         int[][][] dp = new int[R][C][2];
//         for (int i = 0; i < R; i++) {
//             for (int j = 0; j < C; j++) {
//                 dp[i][j][0] = dp[i][j][1] = 1;
//             }
//         }
//         for (int i = 0; i < R; i++) {
//             for (int j = 0; j < C; j++) {
//                 if (i - 1 >= 0) {
//                     if (matrix[i - 1][j] < matrix[i][j]) {
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i - 1][j][0]);
//                     }
//                 }
//                 if (j - 1 >= 0) {
//                     if (matrix[i][j - 1] < matrix[i][j]) {
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i][j - 1][0]);
//                     }
//                 }
//             }
//         }
//         for (int i = R - 1; i >= 0; i--) {
//             for (int j = C - 1; j >= 0; j--) {
//                 if (i + 1 < R) {
//                     if (matrix[i + 1][j] < matrix[i][j]) {
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i + 1][j][1]);
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i + 1][j][0]);
//                     }
//                 }
//                 if (j + 1 < C) {
//                     if (matrix[i][j + 1] < matrix[i][j]) {
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i][j + 1][1]);
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i][j + 1][0]);
//                     }
//                 }
//             }
//         }

//         // for (int i = 0; i < R; i++) {
//         //     for (int j = 0; j < C; j++) {
//         //         System.out.print("[" + dp[i][j][0] + ", " + dp[i][j][1] + "], ");
//         //     }
//         //     System.out.println();
//         // }

//         int longest = 0;
//         for (int i = 0; i < R; i++) {
//             for (int j = 0; j < C; j++) {
//                 if (i + 1 < R) {
//                     if (matrix[i + 1][j] < matrix[i][j]) {
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i + 1][j][1]);
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i + 1][j][0]);
//                     }
//                 }
//                 if (j + 1 < C) {
//                     if (matrix[i][j + 1] < matrix[i][j]) {
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i][j + 1][1]);
//                         dp[i][j][1] = Math.max(dp[i][j][1], 1 + dp[i][j + 1][0]);
//                     }
//                 }
//                 if (i - 1 >= 0) {
//                     if (matrix[i - 1][j] < matrix[i][j]) {
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i - 1][j][1]);
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i - 1][j][0]);
//                     }
//                 }
//                 if (j - 1 >= 0) {
//                     if (matrix[i][j - 1] < matrix[i][j]) {
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i][j - 1][1]);
//                         dp[i][j][0] = Math.max(dp[i][j][0], 1 + dp[i][j - 1][0]);
//                     }
//                 }
//                 longest = Math.max(longest, Math.max(dp[i][j][0], dp[i][j][1]));
//             }
//         }


//         return longest;
//     }
// }