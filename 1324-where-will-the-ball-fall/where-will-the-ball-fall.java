class Solution {
    private int dfs(int[][] grid, int bi) {
        int r = grid.length;
        int c = grid[0].length;
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
    public int[] findBall(int[][] grid) {
        int r = grid.length, c = grid[0].length;

        int[] b = new int[c];
        for (int i = 0; i < c; i++) {
            b[i] = dfs(grid, i);
        }

        return b;   
    }
}