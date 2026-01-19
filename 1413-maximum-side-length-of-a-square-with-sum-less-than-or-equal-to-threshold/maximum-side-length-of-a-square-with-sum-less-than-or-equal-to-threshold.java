class Solution {
    private int r, c;
    private boolean feasible(int[][] ps, int side, int threshold) {
        for (int i = 0; i <= r - side; i++) {
            for (int j = 0; j <= c - side; j++) {
                if (ps[i + side][j + side] - ps[i + side][j] - ps[i][j + side] + ps[i][j] <= threshold) {
                    return true;
                }
            }
        }

        return false;
    }
    public int maxSideLength(int[][] mat, int threshold) {
        this.r = mat.length;
        this.c = mat[0].length;

        int[][] ps = new int[r + 1][c + 1];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ps[i + 1][j + 1] = mat[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }

        int result = 0;
        int low = 1, high = Math.min(r, c);
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(ps, mid, threshold)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
}