class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;
        int[] flatend = new int[r * c];

        int i = 0, j = 0, k = 0;
        boolean posDiag = true;
        for (int d = 0, len = r + c - 1; d < len;  d++) {
            if (posDiag) {
                while (i >= 0 && j < c) {
                    flatend[k++] = mat[i--][j++];
                }
                i++; j--;
                if (j + 1 < c) j++;
                else if (i + 1 < r) i++;
            } else {
                while (i < r && j >= 0) {
                    flatend[k++] = mat[i++][j--];
                }
                i--; j++;
                if (i + 1 < r) i++;
                else if (j + 1 < c) j++;
            }
            posDiag = !posDiag;
        }


        return flatend;
    }
}